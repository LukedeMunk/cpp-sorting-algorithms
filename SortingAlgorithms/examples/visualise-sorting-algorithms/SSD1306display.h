/*
 * File:      SSD1306display.h
 * Class:     SSD1306display
 * Authors:   Luke de Munk
 *
 *  To show graphs on SSD1306 display.
 */
#ifndef SSD1306display_h
#define SSD1306display_h
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeMonoBoldOblique12pt7b.h>

#define SCREEN_WIDTH  128                                                   //OLED display width, in pixels
#define SCREEN_HEIGHT 32                                                    //OLED display height, in pixels

class SSD1306display {
  public:
    Adafruit_SSD1306 display(128, 32, &Wire, -1);

    SSD1306display() {

    }

    
};
#endif
