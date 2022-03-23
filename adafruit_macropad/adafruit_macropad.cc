#include "adafruit_macropad.h"

#include "hardware/gpio.h"

namespace crynsnd {

void Adafruit_MacroPad::Init() {
  gpio_init_mask(MACROPAD_ALL_BUTTONS_GPIO_MASK);
  gpio_set_dir_masked(MACROPAD_ALL_BUTTONS_GPIO_MASK, GPIO_IN);
  // GPIO 0 to 12 are pull-up.
  for (int i = 0; i <= 12; i += 1) {
    gpio_pull_up(i);
  }
}

bool Adafruit_MacroPad::IsKeyPressed(MacroPadKey key) {
  // negate the result, because pull-up.
  return !gpio_get(key);
}

bool Adafruit_MacroPad::IsRotaryButtonPressed() const {
  // negate the result, because pull-up.
  return !gpio_get(ROTARY_BUTTON_GPIO);
}

const uint16_t Adafruit_MacroPad::GetPressedButtons() const {
  return ~(MACROPAD_ALL_BUTTONS_GPIO_MASK & gpio_get_all()); 
}

}  // namespace crynsnd