//
// Created by steph on 2/19/2018.
//

#ifndef STACKS_QUEUES_LLSTACK_H
#define STACKS_QUEUES_LLSTACK_H
#include "node.h"

class llStack {
public:
    llStack() { head = NULL; };     // Constant

    void push( string val ) {         // Constant
        node *temp;
        temp->data = val;
        temp->next = head;
        head = temp;
    };

    void pop() {                    // Constant
        node *temp = head;
        head = head->next;
        cout << temp->data;
        delete temp;
    }

    string top() {                  // Constant
        return head->data;
    }

    bool isEmpty() {                // Constant
        return head == NULL;
    }

    ~llStack() {                    // N
        while( head != NULL ) {
            pop();
        }
    }

private:
    node *head;
};

#endif //STACKS_QUEUES_LLSTACK_H
