//
// Created by steph on 4/9/2018.
//

#ifndef SORTING_HEAPSORT_H
#define SORTING_HEAPSORT_H

#include "sort.h"

template <class type>
class heapSort: public sort {
public:
    heapSort( int l ){
        size = l;
        arr[size];
    }

    // To heapify a subtree rooted with node i which is
    // an index in arr[]. n is size of heap
    void heapify( type temp[], int n, int i )
    {
        int largest = i;  // Initialize largest as root
        int l = 2*i + 1;  // left = 2*i + 1
        int r = 2*i + 2;  // right = 2*i + 2

        // If left child is larger than root
        if ( l < n && temp[l] > temp[largest] )
            largest = l;

        // If right child is larger than largest so far
        if ( r < n && temp[r] > temp[largest] )
            largest = r;

        // If largest is not root
        if ( largest != i )
        {
            swap( temp[i], temp[largest] );

            // Recursively heapify the affected sub-tree
            heapify( arr, n, largest );
        }
    }

    void sortArr( int n ) {
        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        // One by one extract an element from heap
        for (int i=n-1; i>=0; i--)
        {
            // Move current root to end
            swap(arr[0], arr[i]);

            // call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }

    ~heapSort(){ delete arr; }

private:
    type arr[];
    int size;
};

#endif //SORTING_HEAPSORT_H
