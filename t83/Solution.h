#include "../ListNode.h"

class Solution {
public:
    static ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* ans = head;
        if (head == nullptr)    return nullptr;

        while (head->next != nullptr)
        {
            /* code */
            
            if(head->next->val == head->val)
            {
                head->next = head->next->next;
                continue;
            }
            else
            {
                head = head->next;
            }
            
        }
        return ans;
    }

    
};