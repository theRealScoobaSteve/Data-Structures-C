//
// Created by steph on 4/9/2018.
//

#ifndef SORTING_SORT_H
#define SORTING_SORT_H

#include <iostream>
#include <fstream>
using namespace std;


class Sort
{
public:

    Sort(int size);
    ~Sort();

    virtual void insertAllFromFile( const char *filename, int numItemsToLoad ) = 0;
    virtual void print( ostream &out ) = 0;
    virtual void sort() = 0;

protected:
    string *myAr;
    int n;
};


#endif //SORTING_SORT_H
