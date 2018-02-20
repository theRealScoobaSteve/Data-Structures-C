//
// Created by steph on 2/19/2018.
//

#ifndef STACKS_QUEUES_LLSTACK_H
#define STACKS_QUEUES_LLSTACK_H
#include <string>
#include <iostream>
using namespace std;

class llStack {
public:
    class node {
    public:
        string data;
        node *next;
    };

    llStack() { head = NULL; };

    void push(string val) {
        node *temp;
        temp->data = val;
        temp->next = head;
        head = temp;
    };

    void pop() {
        node *temp = head;
        head = head->next;
        cout << temp->data;
        delete temp;
    }

    string top() {
        return head->data;
    }

    bool isEmpty() {
        return head == NULL;
    }

    ~llStack() {
        while( head != NULL ) {
            pop();
        }
    }

private:
    node *head;
};

#endif //STACKS_QUEUES_LLSTACK_H
