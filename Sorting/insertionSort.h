//
// Created by steph on 4/9/2018.
//

#ifndef SORTING_INSERTIONSORT_H
#define SORTING_INSERTIONSORT_H

#include "sort.h"

#include "Sort.h"


class InsertionSort: public Sort
{
public:
    InsertionSort( int size ):Sort(size) {}

    ~InsertionSort() {}

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
        for ( int i=0; i<n; ++i )
            out << myAr[i] << endl;
    }

    void sort() {
        int j;
        string key;
        for ( int i = 1; i < n; i++ ) {
            key = myAr[i];
            j = i-1;

//               Move elements of arr[0..i-1], that are
//               greater than key, to one position ahead
//               of their current position
            while ( j >= 0 && myAr[j] > key ) {
                myAr[j+1] = myAr[j];
                j = j-1;
            }
            myAr[j+1] = key;
        }
    }

private:
};

#endif //SORTING_INSERTIONSORT_H
