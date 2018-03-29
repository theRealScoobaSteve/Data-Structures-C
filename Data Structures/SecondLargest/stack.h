//
// Created by steph on 3/28/2018.
//

#ifndef SECONDLARGEST_STACK_H
#define SECONDLARGEST_STACK_H

#include <vector>
#include <iostream>
using namespace std;



class stack
{
public:
    stack() {
        first = 0;
        second = 0;
    }

    void push( int value ) {
        myStack.push_back(value);
        if( value > first )
        {
            thirdLargest.push_back( second );
            second = first;
            first = value;
        }
        else if( value > second )
        {
            thirdLargest.push_back( second );
            second = value;
        }
        else if( value > thirdLargest.back() )
        {
            thirdLargest.push_back(value);
        }
    }

    void pop() {
        if( myStack.back() == first )
        {
            first = second;
            second = thirdLargest.back();
            thirdLargest.pop_back();
        }
        else if( myStack.back() == second )
        {
            second = thirdLargest.back();
            thirdLargest.pop_back();
        }
        else if( myStack.back() == thirdLargest.front() )
        {
            thirdLargest.pop_back();
        }
        myStack.pop_back();
    }

    int secondLargest() {
        return second;
    }

private:
    int first;
    int second;

    vector<int> thirdLargest;
    vector<int> myStack;

};

#endif //SECONDLARGEST_STACK_H
