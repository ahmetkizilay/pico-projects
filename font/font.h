#ifndef __adafruit_ssd1306_font_h__
#define __adafruit_ssd1306_font_h__

#include <cstdio>

namespace crynsnd {
namespace fonts {

class Font {
 public:
  explicit Font(const uint8_t* font_data) : font(font_data) {}

  virtual const uint8_t GetLetterWidth() const = 0;
  virtual const uint16_t GetLetterIndex(char val) const = 0;
  const uint8_t* font;
};

}  // namespace fonts
}  // namespace crynsnd

#endif  // __adafruit_ssd1306_font_h__
