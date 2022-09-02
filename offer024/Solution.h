//
// Created by Percy on 2022/3/18.
//

#ifndef OFFER024_SOLUTION_H
#define OFFER024_SOLUTION_H


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* nxt) : val(x), next(nxt) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return NULL;
        ListNode* pre = nullptr;
        ListNode* nxt;
        while (head) {
            nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
        }
        return pre;

    }
};


#endif //OFFER024_SOLUTION_H
