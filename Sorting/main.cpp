#include <iostream>

#include "HeapSort.h"
#include "QuickSort.h"
#include "InsertionSort.h"
#include <time.h>
#include <chrono>

using  ns = chrono::nanoseconds;
using get_time = chrono::steady_clock ;

int main() {

    Sort *quickSort = new QuickSort( 50000 );
    Sort *heapSort = new HeapSort( 50000 );
    Sort *insertionSort = new InsertionSort( 50000 );


    const char* FILE = "words.txt";


    clock_t start = clock();
    cout << "Testing Quick Sort!\n";
    quickSort->insertAllFromFile( FILE,50000 );
    quickSort->sort();
    clock_t end = clock();
    double elapsed = ( double )(end - start) * 1000.0 / CLOCKS_PER_SEC;


    cout << "It took " << elapsed << " millisecond(s) to complete quick sort\n";

    start = clock();
    cout << "Testing Heap Sort!\n";
    heapSort->insertAllFromFile( FILE,50000 );
    heapSort->sort();
    end = clock();
    elapsed = ( double )( end - start ) * 1000.0 / CLOCKS_PER_SEC;
    cout << "It took " << elapsed << " millisecond(s) to complete heap sort\n";

    start = clock();
    cout << "Testing Insertion Sort!\n";
    insertionSort->insertAllFromFile(FILE,50000);
    insertionSort->sort();
    end = clock();
    elapsed = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    cout << "It took " << elapsed << " millisecond(s) to complete insertion sort\n";







    return 0;
}