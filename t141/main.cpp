#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    ListNode* node = new ListNode(3);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(-4);
    node->next  = node1;
    node1->next  = node2;
    node2->next  = node3;
    node3->next  = node1;
    Solution sol;
    sol.hasCycle(node);
    return 0;
}
