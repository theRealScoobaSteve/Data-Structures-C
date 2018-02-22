//
// Created by steph on 2/19/2018.
//

#ifndef STACKS_QUEUES_LLQUEUE_H
#define STACKS_QUEUES_LLQUEUE_H
#include "node.h"
#include "queue.h"

class llQueue: public queue {
public:
    llQueue(){ head = NULL; tail = NULL; }  // Constant

    void enq( string val ) {                  // Constant
        node *temp = new node;
        temp->data = val;

       if( isEmpty() ) {
           head = temp;
           tail = temp;
       }
       else {
           temp->next = NULL;
           tail->next = temp;
           tail = temp;
       }
    };

    string deq() {                            // Constant
        node *temp;
        temp = head;
        head = temp->next;
        string word = temp->data;
        delete temp;
        return word;
    }

    string front() {                        // Constant
        return head->data;
    }

    bool isEmpty() {                        // Constant
        return head == NULL;
    }

    ~llQueue() {                            // N
        while( head != NULL ) {
            deq();
        }
    }

private:
    node *head;
    node *tail;
};


#endif //STACKS_QUEUES_LLQUEUE_H
