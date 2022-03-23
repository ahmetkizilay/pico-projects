#include <stdio.h>

#include "adafruit_macropad.h"
#include "pico/stdlib.h"

using ::crynsnd::Adafruit_MacroPad;
using ::crynsnd::MacroPadKey;

int main() {
  // Initialize IO for USB Serial
  stdio_init_all();

  Adafruit_MacroPad macropad;
  macropad.Init();

  while (1) {
    const uint16_t button_mask = macropad.GetPressedButtons();
    for (int key = MacroPadKey::KEY_1; key <= MacroPadKey::KEY_12; key += 1) {
      if ((button_mask >> key) % 2 == 1) {
        printf("%d ", key);
      }
    }
    printf("\n");
    if (macropad.IsRotaryButtonPressed()) {
      printf("Rotary is pressed\n");
    }
    sleep_ms(1000);
  }
}