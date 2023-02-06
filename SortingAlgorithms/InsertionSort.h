/*
 * File:      InsertionSort.h
 * Authors:   Luke de Munk
 * Class:     InsertionSort
 *
 * InsertionSort feature to sort arrays.
*/
#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

class InsertionSort {
  public:
    /**************************************************************************/
    /*!
        @brief  Constructor.
    */
    /**************************************************************************/
    InsertionSort() {

    }

    /**************************************************************************/
    /*!
        @brief  Sorts a list of elements.
        @param  list        Array of elements to be sorted
        @param  n           Length of the array
    */
    /**************************************************************************/
    void sort(int32_t list[], uint32_t n) {
        int32_t key = 0;
        uint32_t j = 0;

        for (uint32_t i = 1; i < n; i++) {
            //TEST
            delay(0);                                                           //Needed, otherwise +-20% of list elements gets random
                                                                                //Not clear why this happens yet
            
            key = list[i];
            j = i - 1;
    
            /* Move elements of list[0..i-1], that are  
            greater than key, to one position ahead  
            of their current position */
            while (j >= 0 && list[j] > key) {
                list[j + 1] = list[j];
                j = j - 1;
            }

            list[j + 1] = key;
        }
    }
};
#endif