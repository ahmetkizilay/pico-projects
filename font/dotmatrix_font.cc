#include "dotmatrix_font.h"

namespace crynsnd {
namespace fonts {

DotMatrix::DotMatrix() : Font{internal::FONT} {};

const uint16_t DotMatrix::GetLetterIndex(char val) const {
  uint16_t i = 0;
  for (; i < internal::ALPHABET_SIZE; i += 1) {
    if (internal::ALL_GLYPHS[i] == val) {
      return i * internal::LETTER_WIDTH;
    }
  }
  return i * internal::LETTER_WIDTH;
}

}  // namespace fonts
}  // namespace crynsnd