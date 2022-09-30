#include <iostream>
#include "Solution.hpp"

int main() {
    MyLinkedList* obj = new MyLinkedList();
    // int param_1 = obj->get(index);
    obj->addAtHead(7);
    obj->addAtHead(2);
    obj->addAtHead(1);
    obj->addAtIndex(3,0);
    obj->deleteAtIndex(2);
    
    obj->addAtHead(6);
    obj->addAtTail(4);
    cout << obj->get(4) << endl;
    obj->addAtHead(4);
    obj->addAtIndex(5,0);
    obj->addAtHead(6);

    
    
    cout << obj->get(2) << endl;
    cout << obj->get(1);
    
    return 0;
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */