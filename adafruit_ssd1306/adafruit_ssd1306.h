#ifndef __crynsnd_adafruit_ssd1306_h__
#define __crynsnd_adafruit_ssd1306_h__

#include <stdio.h>

namespace crynsnd {

#define SSD06_ENABLECHARGEPUMP 0x14
#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMN_ADDRESS 0x21
#define SSD1306_PAGE_ADDRESS 0x22
// 0x26 scroll right, 0x27 scroll left
#define SSD1306_HORIZONTAL_SCROLL_DIRECTION 0x26
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_SETSTARTLINE 0x40
#define SSD1306_SETCONTRAST 0x81
#define SSD1306_CHARGEPUMP 0x8D
#define SSD1306_SETMULTIPLEX 0xA8
#define SSD1306_SEGREMAP 0xA0
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF
#define SSD1306_COMSCANDEC 0xC8
#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9
#define SSD1306_SETCOMPINS 0xDA
#define SSD1306_SETVCOMDETECT 0xDB

#define MISO 16  // PIN 20 (Not used for SSD1306)
#define CS 17    // PIN 22 (Chip Select)
#define SCLK 18  // PIN 24 (Clock)
#define MOSI 19  // PIN 25 (Data pin)

// These two are specific to Adafruit SSD1306
#define RESET 20  // PIN 26
#define DORC 21   // PIN 27 (Data or Command)

#define SPI_PORT spi0

enum HorizontalScrollDirection {
  SCROLL_RIGHT,
  SCROLL_LEFT,
};

enum ScrollFrameRate { RATE_5, RATE_64, RATE_128, RATE_256, RATE_3, RATE_4, RATE_25, RATE_2 };

enum MemoryPage {
  PAGE_0,
  PAGE_1,
  PAGE_2,
  PAGE_3,
  PAGE_4,
  PAGE_6,
  PAGE_7,
};

// This is based on the library by Adafruit. https://github.com/adafruit/Adafruit_SSD1306
// Specifically, the Adafruit library was useful to set the commands to interact with the SSD106
// chip.
class Adafruit_SSD1306 {
 public:
  Adafruit_SSD1306(const uint8_t width, const uint8_t height);
  ~Adafruit_SSD1306();

  void Init();
  void ClearDisplay();
  void SetPixel(uint8_t x, uint8_t y);
  void Display();
  void SetGlyph(uint16_t offset, const uint8_t *data, const uint8_t len);
  void ScrollHorizontally(HorizontalScrollDirection direction, MemoryPage page_start,
                          MemoryPage page_end, ScrollFrameRate frame_rate);
  void StopScroll();

  const uint8_t GetWidth() const { return width_; }
  const uint8_t GetHeight() const { return height_; }

 private:
  const uint8_t width_;
  const uint8_t height_;
  const uint32_t buffer_size_;
  uint8_t *buffer_;

  void WriteCommand(const uint8_t *payload, uint8_t payload_size);
};

}  // namespace crynsnd

#endif  // __crynsnd_adafruit_ssd1306_h__