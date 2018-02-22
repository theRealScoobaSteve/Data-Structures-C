//
// Created by steph on 2/19/2018.
//

#ifndef STACKS_QUEUES_ARSTACK_H
#define STACKS_QUEUES_ARSTACK_H
#include "stack.h"

class arStack: public stack {
public:
    arStack() { front=0; data=new string[60000]; }           // N

    void push( string val ) {                   // N
        if( !isFull() ) {
            if( !isEmpty() ) {
                front++;
            }
            data[front] = val;
        }
    }

    string pop() {                                // N
        if( front > 0 ) {
            int word = front;
            front--;
            return data[word];
        }
        else {
            string word = data[front];
            data[front] = "";
            return word;
        }
    }

    string top() {                              // N
        return data[front];
    }

    bool isEmpty() {                            // N
        return data[front].empty();
    }

    bool isFull() {                             // N
        return front == 60000;
    }

    ~arStack() { front = 0; delete data; } // N
private:
    int front;
    string *data;
};

#endif //STACKS_QUEUES_ARSTACK_H
