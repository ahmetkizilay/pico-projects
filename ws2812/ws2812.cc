#include "ws2812.h"

#include "ws2812.pio.h"

namespace crynsnd {

WS2812::WS2812(PIO pio, uint sm) : pio_(pio), sm_(sm) {}

void WS2812::Init() {
  uint offset = pio_add_program(pio_, &ws2812_program);
  ws2812_program_init(pio_, sm_, offset, 19, 800000, false);
}

void WS2812::WritePixel(const uint8_t r, const uint8_t b, const uint8_t g) const {
  const uint32_t grb = ((uint32_t)(g) << 16) | ((uint32_t)(r) << 8) | (uint32_t)(b);
  pio_sm_put_blocking(pio_, sm_, grb << 8u);
}

WS2812 CreateDefaultInstance() {
  PIO pio = pio0;
  uint sm = pio_claim_unused_sm(pio, true);
  return WS2812(pio, sm);
}

}  // namespace crynsnd