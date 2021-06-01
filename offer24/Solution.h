#include "../ListNode.h"
class Solution {
public:
    static ListNode* reverseListByRecurve(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* newHead = reverseListByRecurve(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
       
    }
        static ListNode* reverseListByIterate(ListNode* head) 
    {

        ListNode* curNode = head;
        ListNode* prevNode =NULL;
        ListNode* nextNode =NULL;
        while (curNode != NULL)
        {
            nextNode = curNode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
        }
        
        return prevNode;
       
    }
};