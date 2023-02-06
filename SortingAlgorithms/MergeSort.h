/*
 * File:      MergeSort.h
 * Authors:   Luke de Munk
 * Class:     MergeSort
 *
 * MergeSort feature to sort arrays.
*/
#ifndef MERGESORT_H
#define MERGESORT_H

class MergeSort {
  public:
    /**************************************************************************/
    /*!
        @brief  Constructor.
    */
    /**************************************************************************/
    MergeSort() {
        
    }

    /**************************************************************************/
    /*!
        @brief  Sorts a list of elements.
        @param  list    Array of elements to be sorted
        @param  n       Length of the array
    */
    /**************************************************************************/
    void sort(int32_t list[], uint32_t n) {
        uint32_t middlePoint = n/2;
        _sort(list, 0, middlePoint);
        _sort(list, middlePoint+1, n);
        _merge(list, 0, middlePoint, n);
    }

  private:
    /**************************************************************************/
    /*!
        @brief  Merges two subarrays of list[].
        @param  list    Array of elements to be sorted
        @param  l       Left index of sub-array
        @param  m       Middle of sub-array
        @param  r       Right index of sub-array
    */
    /**************************************************************************/
    void _merge(int32_t list[], uint32_t l, uint32_t m, uint32_t r) {
        uint32_t n1 = m - l + 1;
        uint32_t n2 = r - m;
    
        int32_t L[n1], R[n2];                                                   //Create temporary arrays
    
        /* Copy data to temp arrays L[] and R[] */
        for (uint32_t i = 0; i < n1; i++)
            L[i] = list[l + i];
        for (uint32_t j = 0; j < n2; j++)
            R[j] = list[m + 1 + j];

        int lIndex = 0;                                                         //Initial index of first subarray
        int rIndex = 0;                                                         //Initial index of second subarray
        int mIndex = l;                                                         //Initial index of merged subarray

        /* Merge the temp arrays back into list[l..r] */
        while (lIndex < n1 && rIndex < n2) {
            if (L[lIndex] <= R[rIndex]) {
                list[mIndex] = L[lIndex];
                lIndex++;
            } else {
                list[mIndex] = R[rIndex];
                rIndex++;
            }
            mIndex++;
        }
    
        /* Copy the remaining elements of
            L[], if there are any */
        while (lIndex < n1) {
            list[mIndex] = L[lIndex];
            lIndex++;
            mIndex++;
        }
    
        /* Copy the remaining elements of
            R[], if there are any */
        while (rIndex < n2) {
            list[mIndex] = R[rIndex];
            rIndex++;
            mIndex++;
        }
    }
    
    /**************************************************************************/
    /*!
        @brief  Sorts a list of elements.
        @param  list    Array of elements to be sorted
        @param  l       Left index of sub-array
        @param  r       Right index of sub-array
    */
    /**************************************************************************/
    void _sort(int32_t list[], uint32_t l, uint32_t r) {
        if(l >= r){
            return;                                                             //Returns recursively
        }

        uint32_t middlePoint = (l+r-1)/2;

        _sort(list, l, middlePoint);
        _sort(list, middlePoint+1, r);
        _merge(list, l, middlePoint, r);
    }
};
#endif