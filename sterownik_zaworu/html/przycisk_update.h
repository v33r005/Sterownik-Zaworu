#pragma once

#ifdef ARDUINO_ARCH_ESP32
#include <HTTPUpdateServer.h>
HTTPUpdateServer httpUpdater;
#else
#include <ESP8266HTTPUpdateServer.h>
ESP8266HTTPUpdateServer httpUpdater;
#endif

namespace Supla {
namespace Html {

class UpdateParameter : public Supla::HtmlElement {
 public:
  UpdateParameter() : HtmlElement(HTML_SECTION_FORM) {}

  void send(Supla::WebSender* sender) {
      sender->send("<div>");
      sender->send("<button type=\"button\" onclick=\"wlaczUpdateServer();\">"
      "Aktualizacja Firmware"
      "</button>");
      
     // sender->send("</div>");
      // form-field END

  sender->send("<script>"
  
  "function wlaczUpdateServer(){"
    "window.location.href='/update';"
    
  "}"
  "</script>");
} // sender
  bool handleResponse(const char* key, const char* value) {
    
    return false;
  }

  void onProcessingEnd() {
      
    
  }

 protected:
  bool checkboxFound[2] = {false, false};
  int32_t button_type_value[2] = {0,0};
  uint32_t relay_state_value[2] = {0,0};
  uint8_t staircase_mode_value[2] = {0,0};
  uint32_t no_timer_value[2] = {0,0};

}; // ModeParameter

}; // namespace Html
}; // namespace Supla