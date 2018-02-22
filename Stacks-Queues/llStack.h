//
// Created by steph on 2/19/2018.
//

#ifndef STACKS_QUEUES_LLSTACK_H
#define STACKS_QUEUES_LLSTACK_H
#include "stack.h"
#include "node.h"

class llStack: public stack {
public:
    llStack() { head = nullptr; }     // Constant

    void push( string val ) {         // Constant
        node *temp = new node;
        temp->data = val;
        temp->next = head;
        head = temp;
    };

    string pop() {                    // Constant
        node *temp = head;
        head = head->next;
        string word = temp->data;
        delete temp;
        return word;
    }

    string top() {                  // Constant
        return head->data;
    }

    bool isEmpty() {                // Constant
        return head == NULL;
    }

    ~llStack() {                    // N
        while( head != NULL ) {
            string word = pop();
        }
    }

private:
    node *head;
};

#endif //STACKS_QUEUES_LLSTACK_H
