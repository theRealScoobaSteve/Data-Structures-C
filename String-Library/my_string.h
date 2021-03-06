//
// Created by Stephen on 2/8/2018.
//

#ifndef STRING_LIBRARY_MY_STRING_H
#define STRING_LIBRARY_MY_STRING_H
#include <iostream>
#include<stdlib.h>
using namespace std;

class my_string {
public:
    class invalidLength { };
    class invalidIndex { };

    my_string();
    my_string( const char* );
    my_string( const my_string& );
    my_string &operator=( const my_string& );
    ~my_string();

    char &operator []( const int index );
    int length() const;
    int indexOf( const char ) const;
    int indexOf( const my_string& ) const;
    bool operator==( const my_string& );
    my_string operator+( const my_string& );
    my_string operator+=( const my_string& );
    my_string reverse() const;

    void print( ostream &out ) const;
    void read( istream &in );

    bool strcmp( const my_string, const my_string ) const;
    char *strcat(char *, char *);
    char *strdup( char* );
    int strlen( char* ) const;

private:
    int size;
    char *str;
};
#endif //STRING_LIBRARY_MY_STRING_H
