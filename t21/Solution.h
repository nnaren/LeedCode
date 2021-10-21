//
// Created by Percy on 2021/10/21.
//

#ifndef T21_SOLUTION_H
#define T21_SOLUTION_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* new_head = new ListNode();
        ListNode* cur = new_head;
        while(l1!= nullptr && l2!= nullptr) {
            if (l1->val > l2->val) {
                cur->next = l2;
                l2 = l2->next;
            } else {
                cur->next = l1;
                l1 = l1->next;
            }
            cur= cur->next;
        }
        if(l1!= nullptr)
        {
            cur->next = l1;
        }
        if(l2!= nullptr)
        {
            cur->next = l2;
        }
        return new_head->next;
    }
};
#endif //T21_SOLUTION_H
