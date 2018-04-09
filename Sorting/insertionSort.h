//
// Created by steph on 4/9/2018.
//

#ifndef SORTING_INSERTIONSORT_H
#define SORTING_INSERTIONSORT_H

#include "sort.h"

template <class type>
class insertionSort: public sort {
public:
    insertionSort( int l ){
        size = l;
        arr[size];
    }

    void sortArr() {
        int i, j, min_idx;

        // One by one move boundary of unsorted subarray
        for (i = 0; i < size-1; i++) {
            // Find the minimum element in unsorted array
            min_idx = i;
            for (j = i+1; j < size; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            // Swap the found minimum element with the first element
            swap(&arr[min_idx], &arr[i]);
        }
    }

    ~insertionSort() { delete list; }

private:
    int size;
    type arr[];
};

#endif //SORTING_INSERTIONSORT_H
