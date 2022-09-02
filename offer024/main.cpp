
// 本用例实现反转链表

#include <iostream>
#include "Solution.h"
int main()
{

    std::cout << "hello" << std::endl;
    ListNode* l1 = new ListNode( 1,new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    Solution s ;
    s.reverseList(l1);
    return 0;
}