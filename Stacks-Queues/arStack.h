//
// Created by steph on 2/19/2018.
//

#ifndef STACKS_QUEUES_ARSTACK_H
#define STACKS_QUEUES_ARSTACK_H
#include "stack.h"

class arStack: public stack {
public:
    arStack() { front=0; data[30000]; }           // N

    void push( string val ) {                   // N
        if( !isEmpty() ) {
            front++;
        }
        data[front] = val;
    }

    void pop() {                                // N
        front--;
    }

    string top() {                              // N
        return data[front];
    }

    bool isEmpty() {                            // N
        return data[front] ==  "";
    }

    bool isFull() {                             // N
        return front == 99;
    }

    ~arStack() { front = 0; data[front] = ""; } // N
private:
    int front;
    string data[];
};

#endif //STACKS_QUEUES_ARSTACK_H
