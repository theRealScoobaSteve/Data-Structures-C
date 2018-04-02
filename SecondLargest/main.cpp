#include <iostream>
#include "stack.h"
using namespace std;

int main () {
    stack myStack;

    myStack.push(5);
    myStack.push(18);
    myStack.push(12);
    myStack.push(99);
    myStack.push(88);
    myStack.pop();
    myStack.pop();
    cout << "The second largest is " << myStack.secondLargest() << endl;

    return 0;
}