#include <iostream>
#include "Solution.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
//    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(4)));
//    ListNode* head2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    // ListNode* head1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    // ListNode* head2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    // ListNode* head3 = new ListNode(2, new ListNode(6));
    // Solution sol;
    // vector<ListNode*> nodes;
    // nodes.push_back(head1);
    // nodes.push_back(head2);
    // nodes.push_back(head3); 
    // ListNode* ans = sol.mergeKLists(nodes);
    // PrintListNode(ans);

    ListNode* head1 = new ListNode(-1, new ListNode(5, new ListNode(11)));
    ListNode* head2 = new ListNode(6, new ListNode(10));

    Solution sol;
    vector<ListNode*> nodes;
    nodes.push_back(nullptr);
    nodes.push_back(head1);
    nodes.push_back(nullptr);
    nodes.push_back(head2); 
    ListNode* ans = sol.mergeKLists(nodes);
    PrintListNode(ans);

    return 0;
}
