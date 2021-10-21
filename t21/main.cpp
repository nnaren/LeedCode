#include <iostream>
#include "Solution.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
//    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(4)));
//    ListNode* head2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* head1 = new ListNode(-9, new ListNode(3));
    ListNode* head2 = new ListNode(5, new ListNode(7));
    Solution sol;
    sol.mergeTwoLists(head1, head2);
    return 0;
}
