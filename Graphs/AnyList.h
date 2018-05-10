//
// Created by steph on 5/9/2018.
//

#ifndef GRAPHS_ANYLIST_H
#define GRAPHS_ANYLIST_H

#include <string>
#include <list>
#include <iostream>
using namespace std;


class AnyList {
public:
    AnyList() { head = nullptr; }

    ~AnyList() { head.clear(); }

    void insert( string value ) {
        head.push_back( value );
    }

    void destroyList() {
        head.clear();
    }

    void printList() {
        list<string> :: iterator i = head.begin();
        for ( i; i != head.end(); ++i ) {
            cout <<  *i << " ";
        }
    }


private:
    list<string> head;
};

#endif //GRAPHS_ANYLIST_H
