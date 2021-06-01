#include <iostream>
#include "Solution.h"
int main()
{
    std::cout << "hello" << std::endl;
    std::cout << "hello" << std::endl;

    ListNode* l1 = 
    new ListNode(0,
    new ListNode(1,
    new ListNode(2,
    new ListNode(3,
    new ListNode(3,
    new ListNode(5,
    new ListNode(5,
    new ListNode(5))))))));

    // ListNode* l1 = 
    // new ListNode(1,
    // new ListNode(1,
    // new ListNode(6
    // )));

    // ListNode* l1 = 
    // new ListNode(1,
    // new ListNode(1,
    // new ListNode(1
    // )));

    // Solution s = Solution(); 
    ListNode* l2 = Solution::deleteDuplicates(l1);
    Show(l2);
    return 0;
}