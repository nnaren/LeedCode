#include <iostream>

#include "../ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return nullptr;
        
        while(head != nullptr) {
            if (head->val == val)
            {
                head = head->next;
                
            }  else {
                break;   
            }
               
        }
        if (head == nullptr) return nullptr;
        ListNode* before = head;
        ListNode* cur = head->next;
        while (cur)
        {
            if(val == cur->val) {
                before->next = cur->next;
            } else {
                before = before->next;
            }
            cur = cur->next;
        }
        return head;
    }
};