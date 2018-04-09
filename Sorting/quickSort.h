//
// Created by steph on 4/9/2018.
//

#ifndef SORTING_QUICKSORT_H
#define SORTING_QUICKSORT_H

#include "sort.h"

template <class type>
class quickSort: public sort {
    quickSort( int l ){
        size = l;
        arr[size];
    }

    int partition ( type temp[], int low, int high ) {
        int pivot = temp[high];    // pivot
        int i = (low - 1);  // Index of smaller element

        for (int j = low; j <= high- 1; j++)
        {
            // If current element is smaller than or
            // equal to pivot
            if (temp[j] <= pivot)
            {
                i++;    // increment index of smaller element
                swap(&temp[i], &temp[j]);
            }
        }
        swap(&temp[i + 1], &temp[high]);
        return (i + 1);
    }

    void sortArr( int low, int high ) {
        if (low < high)
        {
            /* pi is partitioning index, arr[p] is now
               at right place */
            int pi = partition(arr, low, high);

            // Separately sort elements before
            // partition and after partition
            sortArr( low, pi - 1 );
            sortArr( pi + 1, high );
        }
    }

    ~quickSort() { delete arr; }

private:
    int size;
    type arr[];
};

#endif //SORTING_QUICKSORT_H
