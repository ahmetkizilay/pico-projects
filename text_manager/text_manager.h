#ifndef __adafruit_ssd1306_text_manager_h__
#define __adafruit_ssd1303_text_manager_h__

#include <string>

#include "adafruit_ssd1306.h"
#include "font.h"

namespace crynsnd {

using crynsnd::fonts::Font;

class TextManager {
 public:
  explicit TextManager(Adafruit_SSD1306& display, const Font& font);

  // Write to new line
  void WriteLine(const std::string& text);
  // Clear the screen.
  void Clear();

 private:
  uint8_t current_line_ = 0;
  Adafruit_SSD1306& display_;
  const Font& font_;
};

}  // namespace crynsnd

#endif  // __adafruit_ssd1303_text_manager_h__