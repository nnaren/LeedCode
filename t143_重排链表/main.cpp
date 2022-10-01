#include <iostream>
#include "Solution.hpp"

int main() {
    // ListNode * head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode * head = new ListNode(1);
    Solution sol;
    sol.reorderList(head);
    return 0;
}
