//
// Created by steph on 2/19/2018.
//

#ifndef STACKS_QUEUES_ARQUEUE_H
#define STACKS_QUEUES_ARQUEUE_H
#include "queue.h"

class arQueue: public queue {
public:
    arQueue() { tail=0; head=0; data=new string[60000]; }             // N

    void enq( string val ) {                             // N
        if( !isFull() ) {
            if (!isEmpty()) {
                tail++;
                data[tail] = val;
            }
            else {
                data[head] = val;
            }

        }
    }

    string deq() {                                             // N
        int word = head;
        head++;
        return data[word];
    }

    string front() {                                     // N
        return data[head];
    }

    bool isEmpty() {                                     // N
        return data[head].empty();
    }

    bool isFull() {                                      // N
        return head == 60000;
    }

    ~arQueue() { head = 0; tail=0; delete data; }    // N
private:
    int tail;
    int head;
    string *data;
};

#endif //STACKS_QUEUES_ARQUEUE_H
