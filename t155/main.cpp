#include <iostream>
#include "MinStack.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << endl;  //  --> 返回 -3.
    minStack->pop();
    cout << minStack->top() << endl;      //--> 返回 0.
    cout << minStack->getMin() << endl;  // --> 返回 -2.



    return 0;
}
