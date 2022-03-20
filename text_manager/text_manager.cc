#include "text_manager.h"

namespace crynsnd {

TextManager::TextManager(Adafruit_SSD1306& display, const Font& font)
    : display_(display), font_(font) {}

void TextManager::WriteLine(const std::string& text) {
  uint16_t offset = ((uint16_t)current_line_) * display_.GetWidth();
  uint16_t position = 0;
  for (int i = 0; i < text.length(); i += 1) {
    const uint8_t glyph_width = font_.GetLetterWidth(text[i]);
    const uint16_t index = font_.GetLetterIndex(text[i]);
    display_.SetGlyph(offset + position, &font_.font[index], glyph_width);
    position += ((uint16_t) glyph_width) + 1;
    // If the next character will go out of bounds, move on to the next line.
    if ((i < (text.length() - 1)) && (position + glyph_width) > display_.GetWidth()) {
      position = 0;
      current_line_ += 1;
      offset = ((uint16_t)current_line_) * display_.GetWidth();
    }
  }
  display_.Display();
  current_line_ += 1;
}

void TextManager::Clear() {
  display_.ClearDisplay();
  display_.Display();
}
}  // namespace crynsnd