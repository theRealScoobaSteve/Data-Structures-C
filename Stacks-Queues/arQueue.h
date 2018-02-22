//
// Created by steph on 2/19/2018.
//

#ifndef STACKS_QUEUES_ARQUEUE_H
#define STACKS_QUEUES_ARQUEUE_H
#include "queue.h"

class arQueue: public queue {
public:
    arQueue() { tail=0; head=0; data[30000]; }             // N

    void enq( string val ) {                             // N
        if( !isEmpty() ) {
            tail++;
        }
        data[tail] = val;
    }

    void deq() {                                             // N
        head++;
    }

    string front() {                                     // N
        return data[head];
    }

    bool isEmpty() {                                     // N
        return data[head] == "";
    }

    bool isFull() {                                      // N
        return head == 99;
    }

    ~arStack() { head = 0; tail=0; data[head] = ""; }    // N
private:
    int tail;
    int head;
    string data[];
};

#endif //STACKS_QUEUES_ARQUEUE_H
