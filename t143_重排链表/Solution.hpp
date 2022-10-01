#include <iostream>
#include <string>
#include <vector>
#include "../ListNode.h"
using namespace std;

class Solution {
public:
    ListNode * findMidNode(ListNode* head) {
        ListNode *quick = head;
        ListNode *slow = head;
        while (quick->next && quick->next->next)
        {
            quick = quick->next->next;
            slow = slow->next;
        }
        // if(quick->next)
        //     return slow->next;
        return slow->next;
    }
    ListNode * reverseList(ListNode* head) {
        if (head== nullptr || head->next == nullptr  ) 
            return head;
        ListNode * nxt = reverseList(head->next);  // 反转的第一个，原来的最后一个
        head->next->next = head;  //原来的第一个 反转的最后一个
        head->next = nullptr;
        return nxt;
    }
    void  mergeTwoLists(ListNode* head, ListNode* head2) {
        while (head2 != nullptr )  {
            ListNode * head2Next = head2->next;
            head2->next = head->next;
            head->next = head2;
            head = head2->next;
            head2 = head2Next;
        }
        if(head != nullptr) {
            head->next = nullptr;
        }
    }
    
    void reorderList(ListNode* head) {
        ListNode * mid = findMidNode(head);
        // cout << mid->val << endl;
        Show(mid);
        
        ListNode * midReversed = reverseList(mid);
        Show(head);
        Show(midReversed);
        mergeTwoLists(head, midReversed);
        Show(head);
    }   
};