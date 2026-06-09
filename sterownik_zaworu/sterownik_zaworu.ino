
#include "definicje.h"
#include "zmienne.h"
#include "biblioteki.h"
#include "html_classes.h"


void setup() {

  Serial.begin(115200);

  r1 = new Supla::Control::Relay(RELAY_GPIO);

  buttonCfgRelay = new Supla::Control::Button(BUTTON_CFG_RELAY_GPIO, true, true);

  r1->getChannel()->setDefault(SUPLA_CHANNELFNC_VALVE_OPENCLOSE);
  r1->setDefaultStateRestore();

  buttonCfgRelay->configureAsConfigButton(&SuplaDevice);
  buttonCfgRelay->addAction(Supla::TOGGLE, r1, Supla::ON_CLICK_1);

  #include "html.h"
  httpUpdater.setup(suplaServer.getServerPtr(), "/update");
  SuplaDevice.setInitialMode(Supla::InitialMode::StartInCfgMode);
  SuplaDevice.setSuplaCACert(suplaCACert);
  SuplaDevice.setSupla3rdPartyCACert(supla3rdCACert);
  SuplaDevice.setName(devName);

  SuplaDevice.begin();
}

void loop() {
  SuplaDevice.iterate();
 
}
