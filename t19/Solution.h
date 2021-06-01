#include "../ListNode.h"

class Solution {
public:
    static ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* current = head;
        for(int loop=0; loop<n-1 ;loop++)
        {
            current = current->next;
        }
        if(current->next == nullptr)
        {
            head = head->next;
            return head;
        }
        else
        {
            current = current->next;
        }
        ListNode* beforeDelNode = head;


        while((current->next != nullptr))
        {
            
            beforeDelNode = beforeDelNode->next;
            current = current->next;
            

        }
        beforeDelNode->next = beforeDelNode->next->next;

        return head;
    }

    
};