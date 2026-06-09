#pragma once

#include <supla/network/html_element.h>
#include <supla/network/web_sender.h>
#include <supla/storage/config.h>
#include <supla/storage/storage.h>
#include <string.h>

const char *required(bool isRequired) {
  return isRequired ? "required " : "";
}

const char *displayed(bool isDisplayed) {
  return isDisplayed ? "block\">" : "none\">";
}

#include "html/przycisk_update.h"