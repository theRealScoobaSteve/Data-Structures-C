//
// Created by steph on 2/21/2018.
//

#ifndef STACKS_QUEUES_QUEUE_H
#define STACKS_QUEUES_QUEUE_H
#include <string>
#include <iostream>
using namespace std;

class queue {
public:
    queue() { };
    virtual void enq( string val ) { }
    virtual string deq() { }
    virtual string front() { }
    virtual bool isEmpty() { }
    virtual bool isFull() { }
    virtual ~queue() { }
};

#endif //STACKS_QUEUES_QUEUE_H
