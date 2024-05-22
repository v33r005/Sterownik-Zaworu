#define STATUS_LED_GPIO 2
#define RELAY_GPIO 13
#define BUTTON_CFG_RELAY_GPIO 12
#define Alarm_pin 14
#define Czujnik_Wycieku 5

#include <SuplaDevice.h>
#include <supla/network/esp_wifi.h>
#include <supla/control/roller_shutter.h>
#include <supla/control/relay.h>
#include <supla/control/button.h>
#include <supla/control/action_trigger.h>
#include <supla/device/status_led.h>
#include <supla/storage/littlefs_config.h>
#include <supla/network/esp_web_server.h>
#include <supla/network/html/device_info.h>
#include <supla/network/html/protocol_parameters.h>
#include <supla/network/html/status_led_parameters.h>
#include <supla/network/html/wifi_parameters.h>
#include <supla/device/supla_ca_cert.h>
#include <supla/events.h>
#include <supla/sensor/binary.h>
#include <supla/storage/eeprom.h>
Supla::Eeprom eeprom;

Supla::ESPWifi wifi;
Supla::LittleFsConfig configSupla;

Supla::Device::StatusLed statusLed(STATUS_LED_GPIO, false); // inverted state
Supla::EspWebServer suplaServer;
Supla::Sensor::Binary *cz1 = nullptr; 
Supla::Control::Relay *r1 = nullptr;
Supla::Control::Button *buttonCfgRelay = nullptr;

Supla::Html::DeviceInfo htmlDeviceInfo(&SuplaDevice);
Supla::Html::WifiParameters htmlWifi;
Supla::Html::ProtocolParameters htmlProto;
Supla::Html::StatusLedParameters htmlStatusLed;

void setup() {

  pinMode(Alarm_pin, OUTPUT);
  Serial.begin(115200);

  r1 = new Supla::Control::Relay(RELAY_GPIO);
  cz1 = new Supla::Sensor::Binary(Czujnik_Wycieku, false, true);
  buttonCfgRelay = new Supla::Control::Button(BUTTON_CFG_RELAY_GPIO, true, true);

  r1->getChannel()->setDefault(SUPLA_CHANNELFNC_VALVE_OPENCLOSE);
  r1->setDefaultStateRestore();
  cz1->getChannel()->setDefault(SUPLA_CHANNELFNC_NOLIQUIDSENSOR);

  buttonCfgRelay->configureAsConfigButton(&SuplaDevice);
  buttonCfgRelay->addAction(Supla::TOGGLE, r1, Supla::ON_CLICK_1);
  cz1->addAction(Supla::TURN_OFF, r1, Supla::ON_PRESS);
  SuplaDevice.setSuplaCACert(suplaCACert);
  SuplaDevice.setSupla3rdPartyCACert(supla3rdCACert);
  SuplaDevice.setName("Supla Zawor");

  SuplaDevice.begin();
}

void loop() {
  SuplaDevice.iterate();
  if ((cz1->getValue() == true)&&(r1->isOn())){
    r1->turnOff();
    digitalWrite(Alarm_pin, HIGH);
  }
  if ((cz1->getValue() == false) && (digitalRead(BUTTON_CFG_RELAY_GPIO) == LOW)){
    digitalWrite(Alarm_pin, LOW);
  }
}
