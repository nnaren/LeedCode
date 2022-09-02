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

    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

    ListNode* reverseList(ListNode* head) {
        if (!head)
            return NULL;
        ListNode* nxt = head->next;
        ListNode* nn;
        while (!nxt) {
            nn = nxt->next;
            nxt->next = head;
            head = nxt;
            nxt = nn;
        }
        return head;

    }
};