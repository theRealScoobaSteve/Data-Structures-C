//
// Created by steph on 4/9/2018.
//

#ifndef SORTING_QUICKSORT_H
#define SORTING_QUICKSORT_H

#include "sort.h"


class QuickSort: public Sort
{
public:
    QuickSort( int size ) { n = size; myAr = new string[size]; }

    ~QuickSort() {
        delete myAr;
    }

    void insertAllFromFile( const char *filename, int numItemsToLoad ) {
        int i = 0;
        string value;
        ifstream fin;
        fin.open( filename );

        if( !fin ) {
            cout << "Didn't open file\n";
        }


        while( fin >> value && i < numItemsToLoad ) {
            myAr[i] = value;
            i++;
        }

    }

    void print( ostream &out ) {
        for (int i=0; i<n; ++i)
            out << myAr[i] << endl;
    }

    void sort() {
        recQuickSort( 0,n-1 );
    }

    int partition( int first, int last ) {
        string pivot;

        int index;
        int smallIndex;

        swap( first,(first+last)/2 );
        pivot = myAr[first];
        smallIndex = first;

        for(index = first + 1;index <= last;index++) {
            if(myAr[index] < pivot) {
                smallIndex++;
                swap( smallIndex,index );
            }
        }

        swap(first,smallIndex);
        return smallIndex;
    }

    void swap( int first, int second ) {
        string temp;
        temp = myAr[first];
        myAr[first] = myAr[second];
        myAr[second] = temp;
    }

    void recQuickSort( int first, int last ) {

        int pivotLocation;
        if(first < last) {
            pivotLocation = partition( first,last );
            recQuickSort( first,pivotLocation-1 );
            recQuickSort( pivotLocation+1,last );

        }

    }


private:
};

#endif //SORTING_QUICKSORT_H
