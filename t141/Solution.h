//
// Created by Percy on 2021/10/25.
//

#ifndef T141_SOLUTION_H
#define T141_SOLUTION_H
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* twoStep = head;
        while(twoStep  && twoStep->next)
        {
            twoStep = twoStep->next->next;
            head = head->next;
            if(head == twoStep){
                return true;
            }

        }
        return false;
    }
};
#endif //T141_SOLUTION_H
