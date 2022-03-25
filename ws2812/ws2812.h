#ifndef __crynsnd_ws2812_h__
#define __crynsnd_ws2812_h__

#include "hardware/pio.h"

namespace crynsnd {
class WS2812 {
 public:
  WS2812(PIO pio, uint sm);
  void Init();
  void WritePixel(const uint8_t r, const uint8_t b, const uint8_t g) const;
 private:
  PIO pio_;
  uint sm_;
};

WS2812 CreateDefaultInstance();
}  // namespace crynsnd

#endif  // __crynsnd_ws2812_h__
