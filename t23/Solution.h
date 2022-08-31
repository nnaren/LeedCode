//
// Created by Percy on 2021/10/21.
//

#ifndef T21_SOLUTION_H
#define T21_SOLUTION_H

#include "../node_struct.h"
#include <vector>
using namespace std;
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size()-1);
    }

    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
        if(left == right)
            return lists[left];
        if(left > right)
            return nullptr;
        int mid = (right + left)/2;
        ListNode* lList=merge(lists, left, mid);
        ListNode* rList = merge(lists, mid+1, right);
        return mergeTwoLists(lList, rList);

    }
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
