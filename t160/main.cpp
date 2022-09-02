#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
//    ListNode* a1= new ListNode(4);
//    ListNode* a2= new ListNode(1);
//    ListNode* c1= new ListNode(8);
//    ListNode* c2= new ListNode(4);
//    ListNode* c3= new ListNode(5);
//    a1->next = a2;
//    a2->next = c1;
//    c1->next = c2;
//    c2->next = c3;
//
//    ListNode* b1= new ListNode(5);
//    ListNode* b2= new ListNode(0);
//    ListNode* b3= new ListNode(1);
//    b1->next = b2;
//    b2->next = b3;
//    b3->next = c1;

    ListNode* a1= new ListNode(4);
    Solution sol;
    sol.getIntersectionNode(a1, a1);
    return 0;
}
