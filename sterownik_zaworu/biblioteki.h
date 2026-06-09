#pragma once

/************Ekspandery****************/
#include "PCA9685.h"
PCA9685 pasek1(0x40);
PCA9685 pasek2(0x41);
/**************************************/

#include <SuplaDevice.h>
#include <supla/network/esp_wifi.h>
#include <supla/control/roller_shutter.h>
#include <supla/control/relay.h>

#include <supla/control/button.h>

Supla::Control::Relay *r1 = nullptr;
Supla::Control::Button *buttonCfgRelay = nullptr;

#include <supla/control/action_trigger.h>
#include <supla/device/status_led.h>
#include <supla/storage/littlefs_config.h>
#include <supla/network/html/div.h>
#include <supla/network/html/h3_tag.h>
#include <supla/network/html/device_info.h>
#include <supla/network/html/protocol_parameters.h>
#include <supla/network/html/status_led_parameters.h>
#include <supla/network/html/wifi_parameters.h>
#include <supla/device/supla_ca_cert.h>
#include <supla/events.h>
#include <supla/network/html/custom_parameter.h>
#include <supla/network/html/custom_text_parameter.h>
#include <supla/network/html/custom_checkbox_parameter.h>
#include <supla/network/html/text_cmd_input_parameter.h>
#include <supla/network/html/select_input_parameter.h>
#include <supla/network/html/select_cmd_input_parameter.h>

#include <supla/control/virtual_relay.h>
Supla::Control::VirtualRelay *WebSrv_ = nullptr;
Supla::Control::VirtualRelay *Ustaw_Minimum = nullptr;
Supla::Control::VirtualRelay *Ustaw_Maksimum = nullptr;
Supla::Control::VirtualRelay *kierunek_gora = nullptr;
Supla::Control::VirtualRelay *kierunek_dol = nullptr;

#include <supla/network/esp_web_server.h>
#include <supla/network/client.h>
Supla::EspWebServer suplaServer;
#include <supla/storage/eeprom.h>
Supla::Eeprom eeprom;
#include <supla/mutex.h>
Supla::Mutex *oMutex = nullptr;

Supla::ESPWifi wifi;
Supla::LittleFsConfig configSupla(4096);

Supla::Device::StatusLed statusLed(STATUS_LED_GPIO, true);