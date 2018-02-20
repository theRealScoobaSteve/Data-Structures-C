//
// Created by steph on 2/19/2018.
//

#ifndef STACKS_QUEUES_ARSTACK_H
#define STACKS_QUEUES_ARSTACK_H
#include <string>
#include <iostream>
using namespace std;

class arStack {
public:
    arStack() { front=0; data[100]; };

    void push( string val ) {
        if( !isEmpty() ) {
            front++;
        }
        data[front] = val;
    }

    void pop() {
        front--;
    }

    string top() {
        return data[front];
    }

    bool isEmpty() {
        return data[front] ==  "";
    }

    bool isFull() {
        return front == 99;
    }

    ~arStack() { front = 0; data[front] = ""; }
private:
    int front;
    string data[];
};

#endif //STACKS_QUEUES_ARSTACK_H
