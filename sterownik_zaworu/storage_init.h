#pragma once

//******************własna nazwa*****************************
  Supla::Storage::Init();
  auto cfg = Supla::Storage::ConfigInstance();
  if (Supla::Storage::ConfigInstance()->getString(DEV_NAME, devName, 30)) {
    SUPLA_LOG_DEBUG("# Param[%s]: %s", DEV_NAME, devName);
  } else {
    Supla::Storage::ConfigInstance()->setString(DEV_NAME, "Supla-Zawor");
  }
//****************************************************************