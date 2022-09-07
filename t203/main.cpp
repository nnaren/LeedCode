#include <iostream>
#include "Solution.hpp"

int main() {
    ListNode* list = new ListNode(7, new ListNode(7, new ListNode(7, new ListNode(7))));
    Solution sol;
    sol.removeElements(list, 7);
    return 0;
}
