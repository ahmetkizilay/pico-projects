#ifndef __crynsnd_adafruit_macropad_h__
#define __crynsnd_adafruit_macropad_h__

#include <cstdio>

// 13 buttons from 0 to 12
// GPIO 0 is Rotary button
// GPIO 1-12 are keys
#define MACROPAD_ALL_BUTTONS_GPIO_MASK 0b1111111111111
#define ROTARY_BUTTON_GPIO 0

namespace crynsnd {
enum MacroPadKey {
  KEY_1 = 1,
  KEY_2,
  KEY_3,
  KEY_4,
  KEY_5,
  KEY_6,
  KEY_7,
  KEY_8,
  KEY_9,
  KEY_10,
  KEY_11,
  KEY_12,
};

const uint8_t ROTARY_BUTTON = 0;

class Adafruit_MacroPad {
 public:
  void Init();
  bool IsKeyPressed(MacroPadKey key);
  bool IsRotaryButtonPressed() const;
  // Returns the bit mask for button pressed status from 0 to 13. 
  const uint16_t GetPressedButtons() const;
  
};
}  // namespace crynsnd

#endif  // __crynsnd_adafruit_macropad_h__