//
// Created by Percy on 2021/10/25.
//

#ifndef T160_SOLUTION_H
#define T160_SOLUTION_H
using namespace std;
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };

class Solution {
public:
// A尾结点和B尾结点 一样则相交，否则不相交
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        ListNode * tempA = headA;
        while(tempA) {
            lenA++;
            tempA=tempA->next;
        }
        int lenB = 0;
        ListNode * tempB = headB;
        while(tempB) {
            lenB++;
            tempB=tempB->next;
        }
        if(!lenA || !lenB)
            return nullptr;
        int minAB = min(lenA, lenB);
        ListNode* res =nullptr;
        for(int i = 0 ; i < minAB;i++)
        {
            tempA = headA;
            tempB = headB;
            for(int j=0;j<(lenA-1-i);j++)
            {
                tempA=tempA->next;

            }
            for(int j=0;j<(lenB-1-i);j++)
            {

                tempB=tempB->next;
            }
            if(tempA == tempB)
            {
                res = tempA;
            }

        }
        return res;
    }
};
#endif //T160_SOLUTION_H
