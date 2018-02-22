//
// Created by Stephen on 2/8/2018.
//
#ifndef STRING_LIBRARY_MY_STRING_H
#define STRING_LIBRARY_MY_STRING_H
#include <iostream>
#include<stdlib.h>
using namespace std;
#include "./node.h"

class my_string {
public:
    my_string();
    my_string( const char* );
    my_string( const my_string& );
    my_string &operator=( const my_string& );
    ~my_string();

    friend bool strcmp( my_string, my_string );
    friend my_string strcat( node *first, node *second );

    char operator []( const int index );
    int length() const;
    int indexOf( const char ) const;
    int indexOf( const my_string& ) const;
    bool operator==( const my_string& );
    my_string operator+( const my_string& );
    my_string &operator+=( const my_string& );
    my_string reverse();

    void print( ostream &out ) const;
    void read( istream &in );
private:
    void clear();
    node *head;
};
#endif //STRING_LIBRARY_MY_STRING_H
