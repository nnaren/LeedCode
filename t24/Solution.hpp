#include <iostream>
#include "../ListNode.h"
#include <vector>
using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans = new ListNode(0, head);
        ListNode* before = ans;
        while(before->next != nullptr && before->next->next!=nullptr) {
            ListNode* node1 = before->next;
            ListNode* node2 = before->next->next;
            before->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            before = node1;
        }
        return ans->next;
    }

    ListNode* swapPairsUseRecursion(ListNode* head) {
        if(head == nullptr || head->next == nullptr) 
            return head;
        ListNode* temp = head->next;    // 第二节点
        head->next  = swapPairsUseRecursion(temp->next);  // 第一节点 》》 下次迭代的头节点
        temp->next = head;  // 第二节点 》》 第一节点
        return temp;   // 第二节点
        
    }
};