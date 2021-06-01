#include <iostream>
#include "Solution.h"
int main()
{
    std::cout << "hello" << std::endl;
    std::cout << "hello" << std::endl;
    ListNode* l1 = new ListNode( 9,new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9,new ListNode(9, new ListNode(9)))))));

    ListNode* l2 = new ListNode( 9,new ListNode(9, new ListNode(9,new ListNode(9))));
    // Solution s = Solution(); 
    Solution::addTwoNumbers(l1, l2);
    return 0;
}