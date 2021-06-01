// 本用例实现反转链表

#include <iostream>
#include "Solution.h"
int main()
{

    std::cout << "hello" << std::endl;
    ListNode* l1 = new ListNode( 1,new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    // Solution s = Solution(); 
    ListNode* l2 = Solution::reverseListByRecurve(l1);
    Show(l2);
    ListNode* l3 = Solution::reverseListByIterate(l1);
    Show(l3);
    return 0;
}