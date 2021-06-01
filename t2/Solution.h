#include "ListNode.h"

class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {


        int n1 = 0, n2 = 0, carryBit = 0;
        ListNode* head = new ListNode();
        ListNode* current = head;
 
        while((l1 != nullptr) || (l2 != nullptr) || (0 != carryBit))
        {
            if(l1 == nullptr)
            {
                n1 = 0;
            }
            else
            {
                n1 = l1->val;
                l1 = l1->next;
            }
            
            if(l2 == nullptr)
            {
                n2 = 0;
            }
            else
            {
                n2 = l2->val;
                l2 = l2->next;
            }

            cout << (n1+n2+carryBit) % 10 << endl;
            current->next = new ListNode((n1+n2+carryBit) % 10);

            current = current->next;
            carryBit = (n1+n2+carryBit) / 10;

        }

        return head;
    }
    
};

// class Solution {
// public:
//     static ListNode*   addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* head = new ListNode();
//         int n1 = 0, n2 = 0, carry = 0;
//         int n3[5] = {1, 3};
//         ListNode* current = head;
//         while(l1!=nullptr||l2!=nullptr||carry!=0)
//         {
//             if(l1==nullptr)
//             {
//                 n1 = 0;
//             }
//             else
//             {
//                 n1 = l1->val;
//                 l1 = l1->next;
//             }
//             if(l2==nullptr)
//             {
//                 n2 = 0;
//             }
//             else
//             {
//                 n2 = l2->val;
//                 l2 = l2->next;
//             }
//             current->next = new ListNode((n1+n2+carry)%10);
//             current = current->next;
//             carry = (n1+n2+carry)/10;
//         }
//         return head->next;
//     }
// };