#include <iostream>
#include "Solution.h"
int main()
{
    std::cout << "hello" << std::endl;
    std::cout << "hello" << std::endl;
    ListNode* l1 = new ListNode( 1,new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    // Solution s = Solution(); 
    ListNode* l2 = Solution::removeNthFromEnd(l1, 2);
    Show(l2);
    return 0;
}