//
// Created by steph on 4/9/2018.
//

#ifndef SORTING_SORT_H
#define SORTING_SORT_H

#include <iostream>
#include <fstream>
using namespace std;

template <class type>
class sort {
public:
    sort(){}

    void readFromFile( char *file, int amount ) {}

    void print( ostream &out ) {}

    virtual void sortArr() {}

    virtual void swap( type *xp, type *yp ) {
        type temp = *xp;
        *xp = *yp;
        *yp = temp;
    }

    virtual ~sort() {}
};


#endif //SORTING_SORT_H
