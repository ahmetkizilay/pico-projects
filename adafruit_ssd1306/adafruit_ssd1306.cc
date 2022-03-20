#include "adafruit_ssd1306.h"

#include <string.h>

#include <cstdlib>

#include "hardware/spi.h"
#include "pico/stdlib.h"

namespace crynsnd {

Adafruit_SSD1306::Adafruit_SSD1306(uint8_t width, uint8_t height)
    : width_(width), height_(height), buffer_size_(width * ((height + 7) / 8)) {
  buffer_ = (uint8_t *)malloc(buffer_size_);
}

Adafruit_SSD1306::~Adafruit_SSD1306() {
  if (buffer_ != nullptr) {
    free(buffer_);
    buffer_ = nullptr;
  }
}
void Adafruit_SSD1306::Init() {
  spi_init(SPI_PORT, 500000);

  // Initialise GPIO pins for SPI communication
  gpio_set_function(MISO, GPIO_FUNC_SPI);
  gpio_set_function(SCLK, GPIO_FUNC_SPI);
  gpio_set_function(MOSI, GPIO_FUNC_SPI);

  gpio_init(CS);               // Initialise CS Pin
  gpio_set_dir(CS, GPIO_OUT);  // Set CS as output
  gpio_put(CS, 1);             // Set CS High to indicate no currect SPI communication

  gpio_init(RESET);               // Initialise RESET Pin
  gpio_set_dir(RESET, GPIO_OUT);  // Set RESET as output

  gpio_init(DORC);               // Initialise DORC Pin
  gpio_set_dir(DORC, GPIO_OUT);  // Set DORC as output

  // Initialize Reset Sequence
  gpio_put(RESET, 1);
  sleep_ms(1);
  gpio_put(RESET, 0);
  sleep_ms(10);
  gpio_put(RESET, 1);

  static const uint8_t init1[] = {SSD1306_DISPLAYOFF,
                                  // Suggested ration is 0x80
                                  SSD1306_SETDISPLAYCLOCKDIV, 0x80, 
                                  // Multiplex ratio needs to be between 16 and 63.
                                  SSD1306_SETMULTIPLEX,
                                  (uint8_t)(height_ - 1)};
  WriteCommand(init1, sizeof(init1));

  static const uint8_t init2[] = {SSD1306_SETDISPLAYOFFSET, 0, SSD1306_SETSTARTLINE | 0x0,
                                  // Assuming power by the controller.
                                  // For external vcc, disable using 0x10.
                                  SSD1306_CHARGEPUMP, SSD06_ENABLECHARGEPUMP};
  WriteCommand(init2, sizeof(init2));

  static const uint8_t init3[] = {// Horizontal memory mode
                                  SSD1306_MEMORYMODE, 0x00,
                                  // Column address 127 is mapped to SEG0
                                  SSD1306_SEGREMAP | 0x1,
                                  // Scan from COM[0] to COM[N-1]
                                  SSD1306_COMSCANDEC};
  WriteCommand(init3, sizeof(init3));

  static const uint8_t contrast[] = {SSD1306_SETCONTRAST, 0xCF};
  WriteCommand(contrast, sizeof(contrast));

  static const uint8_t com_pins[] = {SSD1306_SETCOMPINS, 0x12};
  WriteCommand(com_pins, sizeof(com_pins));

  static const uint8_t precharge[] = {SSD1306_SETPRECHARGE, 0xF1};
  WriteCommand(precharge, sizeof(precharge));

  static const uint8_t init5[] = {// Adjust VCOMH Regulator output.
                                  // Selected value corresponds to ~ 0.77 x VCC (RESET)
                                  SSD1306_SETVCOMDETECT, 0x20, SSD1306_DISPLAYALLON_RESUME,
                                  // 0 in RAM means pixel off.
                                  SSD1306_NORMALDISPLAY, SSD1306_DEACTIVATE_SCROLL,
                                  SSD1306_DISPLAYON};
  WriteCommand(init5, sizeof(init5));
}

void Adafruit_SSD1306::ClearDisplay() { memset(buffer_, 0, buffer_size_); }

void Adafruit_SSD1306::SetPixel(uint8_t x, uint8_t y) {
  buffer_[x + (y / 8) * width_] |= (1 << (y % 8));
}

void Adafruit_SSD1306::SetGlyph(uint16_t offset, const uint8_t* data, const uint8_t len) {
  memcpy(&buffer_[offset], data, len);
}

void Adafruit_SSD1306::Display() {
  static const uint8_t pre_write[] = {SSD1306_PAGE_ADDRESS,   0,   0xFF,
                                      SSD1306_COLUMN_ADDRESS, 0x0, (uint8_t)(width_ - 1)};
  WriteCommand(pre_write, sizeof(pre_write));

  gpio_put(DORC, 1);
  gpio_put(CS, 0);  // Indicate beginning of communication
  spi_write_blocking(SPI_PORT, buffer_, buffer_size_);
  gpio_put(CS, 1);  // Signal end of communication
}

void Adafruit_SSD1306::WriteCommand(const uint8_t *payload, uint8_t payload_size) {
  gpio_put(DORC, 0);
  gpio_put(CS, 0);  // Indicate beginning of communication
  spi_write_blocking(SPI_PORT, payload, payload_size);
  gpio_put(CS, 1);  // Signal end of communication
}

}  // namespace crynsnd