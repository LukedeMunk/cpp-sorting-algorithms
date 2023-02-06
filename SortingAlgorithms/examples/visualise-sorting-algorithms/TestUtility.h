/*
 * File:      TestUtility.h
 * Authors:   Luke de Munk
 *
 * Test utility test arrays.
*/
#ifndef TESTUTILITY_H
#define TESTUTILITY_H
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeMonoBoldOblique12pt7b.h>

#define SCREEN_WIDTH  128                                                   //OLED display width, in pixels
#define SCREEN_HEIGHT 64                                                    //OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void initDisplay() {
    delay(100);                                                               //This delay is needed to let the display to initialize
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);                                //Initialize display with the I2C address of 0x3C0
    display.clearDisplay();                                                   //Clear the display
    display.setTextColor(WHITE);                                              //Set color of the text
    display.setTextWrap(false);                                               //Set wrapping, off
    display.setTextSize(2);                                                   //Set text size. We are using a custom font so you should always use the text size of 0. same as 1
    display.dim(0);                                                           //Set brightness, 0 is maximum and 1 is a little dim
    display.clearDisplay();                                                   //Clear the display
    display.setCursor(45, 8);
    display.println("Test");
    display.display();
    display.setRotation(2);                                                   //Set orientation. Goes from 0, 1, 2 or 3
}

/**************************************************************************/
/*!
    @brief  Shows a list of elements on a display.
    @param  list    Array of elements to be sorted
    @param  n       Length of the array
*/
/**************************************************************************/
void showList(int32_t list[], uint32_t n) {
    display.clearDisplay();
    uint16_t height = 0;

    if (n > SCREEN_WIDTH) {
        n = SCREEN_WIDTH;
    }

    for (uint16_t x = 0; x < n; x++) {
        if (list[x] > SCREEN_HEIGHT) {
            height = SCREEN_HEIGHT;
        } else {
            height = list[x];
        }
        for (uint16_t y = 0; y < height; y++) {
            display.drawPixel(x, y, 1);
        }
    }
    display.display();
    delay(10);
}

/**************************************************************************/
/*!
    @brief  Prints a list of elements.
    @param  list    Array of elements to be sorted
    @param  n       Length of the array
*/
/**************************************************************************/
void printList(int32_t list[], uint32_t n) {
    Serial.print("[");
    
    for (int32_t i = 0; i < n; i++) {
        Serial.print(list[i]);
        
        if (i == n-1) {
            Serial.println("]");
        } else {
            Serial.print(", ");
        }
    }
    delay(10);
}

/**************************************************************************/
/*!
    @brief  Generates random elements in a list.
    @param  list    Array of elements to be sorted
    @param  n       Length of the array
    @param  min     Minimum value of an element
    @param  max     Maximum value of an element
*/
/**************************************************************************/
void randomList(int32_t list[], uint32_t n, int32_t min = 0, int32_t max = 100) {
    for (int32_t i = 0; i < n; i++) {
        list[i] = random(min, max);
    }
}

/**************************************************************************/
/*!
    @brief  Shuffles a list of elements.
    @param  list    Array of elements to be sorted
    @param  n       Length of the array
*/
/**************************************************************************/
void shuffle(int32_t list[], uint32_t n) {
    /* Based on randomized index */
    for (int32_t i = 0; i < n; i++) {
        uint32_t randIndex = random(i, n);                                  //Generate a random index between i and n, index < i is already randomized
        
        /* Swap elements */
        int32_t temp = list[i];
        list[i] = list[randIndex];
        list[randIndex] = temp;
    }
}
#endif
