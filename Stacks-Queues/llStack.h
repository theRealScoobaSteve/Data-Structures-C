//
// Created by steph on 2/19/2018.
//

#ifndef STACKS_QUEUES_LLSTACK_H
#define STACKS_QUEUES_LLSTACK_H
#include <string>
using namespace std;

class llStack {
public:
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
        
    }

    bool isEmpty() {
        return head == NULL;
    }

private:
    class node {
    public:
        string data;
        node *next;
    };
    node *head;
};

#endif //STACKS_QUEUES_LLSTACK_H
