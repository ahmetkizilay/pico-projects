

#include <stdio.h>
#include <string.h>

#include <cstdlib>

#include "adafruit_ssd1306.h"
#include "dotmatrix_font.h"
#include "hardware/spi.h"
#include "pico/stdlib.h"
#include "text_manager.h"

#define WIDTH 128
#define HEIGHT 64

using ::crynsnd::Adafruit_SSD1306;
using ::crynsnd::HorizontalScrollDirection;
using ::crynsnd::MemoryPage;
using ::crynsnd::ScrollFrameRate;
using ::crynsnd::TextManager;
using ::crynsnd::fonts::DotMatrix;

int main() {
  // Initialize IO for USB Serial
  stdio_init_all();
  printf("STARTING\n");

  Adafruit_SSD1306 display(WIDTH, HEIGHT);
  display.Init();

  const DotMatrix font;
  TextManager text_manager(display, font);

  text_manager.Clear();

  text_manager.WriteLine("ABCDEFGHIJKLMNOPQRSTUVWXYZ.0123456789+-=/\\[] ?<>^:\"'!%()|@#,_");
  text_manager.WriteLine("");
  text_manager.WriteLine("ABCDEFGHIJKLMNOPQRSTUVWXYZ.0123456789+-=/\\[] ?<>^:\"'!%()|@#,_");

  display.ScrollHorizontally(HorizontalScrollDirection::SCROLL_LEFT, MemoryPage::PAGE_0,
                             MemoryPage::PAGE_0, ScrollFrameRate::RATE_5);
  sleep_ms(4000);
  display.StopScroll();

  while (1) {
  }
}
