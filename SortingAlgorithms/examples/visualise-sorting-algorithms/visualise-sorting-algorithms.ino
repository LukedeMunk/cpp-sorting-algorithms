/*
 * File:      sorting.ino
 * Author:    Luke de Munk
 * 
 * Example for the sorting package with visualisation option. Needs an SSD1306 display.
 * For more info (including wiring) checkout: https://github.com/LukedeMunk/cpp-sorting-algorithms
 */
#include "QuickSort.h"
#include "MergeSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "TestUtility.h"

#define SCREEN_WIDTH  128                                                   //OLED display width, in pixels
#define SCREEN_HEIGHT 32                                                    //OLED display height, in pixels

QuickSort qs;
MergeSort ms;
SelectionSort ss;
InsertionSort is;
BubbleSort bs;

#define LENGTH      128
int32_t list[LENGTH];                                                       //Create an array

/**************************************************************************/
/*!
  @brief    Setup board and do tests.
*/
/**************************************************************************/
void setup() {
    Serial.begin(115200);
    initDisplay();
    
    randomList(list, LENGTH, 0, 64);                                        //Randomize items in array

    uint32_t startTime = 0;                                                 //Variables to test speed
    uint32_t elapsedTime = 0;

    Serial.print("Unsorted list: ");
    printList(list, LENGTH);

    /* QuickSort */
    startTime = millis();
    Serial.print("test1");
    qs.sort(list, LENGTH);
    Serial.print("test2");
    elapsedTime = millis() - startTime;
    Serial.print("Quicksorted list: ");
    printList(list, LENGTH);
    Serial.print("Time elapsed (ms): ");
    Serial.println(elapsedTime);

    shuffle(list, LENGTH);

    /* MergeSort */
    startTime = millis();
    ms.sort(list, LENGTH);
    elapsedTime = millis() - startTime;
    Serial.print("Mergesorted list: ");
    printList(list, LENGTH);
    Serial.print("Time elapsed (ms): ");
    Serial.println(elapsedTime);

    shuffle(list, LENGTH);

    /* SelectionSort */
    startTime = millis();
    ss.sort(list, LENGTH);
    elapsedTime = millis() - startTime;
    Serial.print("Selectionsorted list: ");
    printList(list, LENGTH);
    Serial.print("Time elapsed (ms): ");
    Serial.println(elapsedTime);

    shuffle(list, LENGTH);

    /* InsertionSort */
    startTime = millis();
    is.sort(list, LENGTH);//HAS A BUG
    elapsedTime = millis() - startTime;
    Serial.print("Insertionsorted list: ");
    printList(list, LENGTH);
    Serial.print("Time elapsed (ms): ");
    Serial.println(elapsedTime);

    shuffle(list, LENGTH);

    /* BubbleSort */
    startTime = millis();
    bs.sort(list, LENGTH);//HAS A BUG
    elapsedTime = millis() - startTime;
    Serial.print("Bubblesorted list: ");
    printList(list, LENGTH);
    Serial.print("Time elapsed (ms): ");
    Serial.println(elapsedTime);
}

/**************************************************************************/
/*!
  @brief    Mainloop.
*/
/**************************************************************************/
void loop() {
  //Serial.println("loop");
  delay(10000);
}
