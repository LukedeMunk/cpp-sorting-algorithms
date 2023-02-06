/*
 * File:      TestUtility.h
 * Authors:   Luke de Munk
 *
 * Test utility to test different sorting algorithms to sort arrays.
*/
#ifndef TESTUTILITY_H
#define TESTUTILITY_H

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