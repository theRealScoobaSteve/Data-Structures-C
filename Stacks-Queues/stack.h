//
// Created by steph on 2/21/2018.
//

#ifndef STACKS_QUEUES_STACK_H
#define STACKS_QUEUES_STACK_H
#include <string>
#include <iostream>
using namespace std;

class stack {
public:
    virtual void push( string val ) { }
    virtual void pop() { }
    virtual string top() { }
    virtual bool isEmpty() { }
    virtual bool isFull() { }
    virtual ~stack() { }
};

#endif //STACKS_QUEUES_STACK_H
