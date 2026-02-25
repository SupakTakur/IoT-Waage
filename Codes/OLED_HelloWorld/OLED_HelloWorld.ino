#include <Wire.h>
#include <U8g2lib.h>

// Für die meisten 1.3" SH1106 I2C Displays:
U8G2_SH1106_128X64_NONAME_F_HW_I2C display(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  display.begin();
  display.clearBuffer();
  display.setFont(u8g2_font_ncenB14_tr);
  display.drawStr(0, 30, "Hello");
  display.drawStr(0, 60, "World");
  display.sendBuffer();
}

void loop() {}
