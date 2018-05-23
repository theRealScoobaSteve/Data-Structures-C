//
// Created by steph on 4/9/2018.
//

#ifndef SORTING_HEAPSORT_H
#define SORTING_HEAPSORT_H

#include "sort.h"

class HeapSort: public Sort
{
public:
    HeapSort( int size ) { n = size; myAr = new string[size]; }

    ~HeapSort() {

        delete [] myAr;
    }

    void heapify( string temp[], int n, int i ) {
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
        if ( largest != i ) {

            swap( temp[i], temp[largest] );

            // Recursively heapify the affected sub-tree
            heapify( myAr, n, largest );
        }


    }

    void sort() {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify( myAr, n, i );

        // One by one extract an element from heap
        for ( int i=n-1; i>=0; i-- )
        {
            // Move current root to end
            swap( myAr[0], myAr[i] );

            // call max heapify on the reduced heap
            heapify( myAr, i, 0 );
        }
    }

    void print( ostream &out ) {
        for (int i=0; i<n; ++i)
            out << myAr[i] << " ";
        out << "\n";
    }

    void insertAllFromFile( const char *filename, int numItemsToLoad ) {
        int i = 0;
        string value;
        ifstream fin;
        fin.open( filename );

        if(!fin) {
            cout << "Didn't open file\n";
        }


        while( fin >> value && i < numItemsToLoad ) {
            myAr[i] = value;
            i++;
        }

    }

};
#endif //SORTING_HEAPSORT_H
