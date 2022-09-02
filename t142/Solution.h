//
// Created by Percy on 2021/10/25.
//

#ifndef T142_SOLUTION_H
#define T142_SOLUTION_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int hasLoop = false;
        while(fast  && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                hasLoop =  true;
                break;
            }
        }
        if(hasLoop){
            while(fast != head)
            {
                head = head->next;
                fast = fast->next;
            }
            return fast;
        } else {
            return nullptr;
        }
    }

};
#endif //T142_SOLUTION_H
