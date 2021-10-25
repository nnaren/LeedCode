//
// Created by Percy on 2021/10/25.
//

#ifndef T155_MINSTACK_H
#define T155_MINSTACK_H
#include <stack>

using namespace std;
class MinStack {
    stack<int> nomalStack_;
    stack<int> minStack_;
public:
    MinStack() {

    }

    void push(int val) {
        if(minStack_.empty() || val < minStack_.top())
        {
            minStack_.push(val);
            nomalStack_.push(val);
        } else {
            minStack_.push( minStack_.top());
            nomalStack_.push(val);
        }
    }

    void pop() {
        nomalStack_.pop();
        minStack_.pop();

    }

    int top() {
        return nomalStack_.top();
    }

    int getMin() {
        return minStack_.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#endif //T155_MINSTACK_H
