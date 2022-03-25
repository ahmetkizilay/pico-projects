#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "ws2812.h"

using ::crynsnd::WS2812;

int main() {
  WS2812 ws2812 = crynsnd::CreateDefaultInstance();
  ws2812.Init();

  while (1) {
    for (int i = 0; i < 12; i += 1) {
      int val = rand() & 100;
      if (val < 10) {
        ws2812.WritePixel(128, 22, 176);
      } else {
        ws2812.WritePixel(0, 0, 0);
      }
    }
    sleep_ms(250);
  }
}