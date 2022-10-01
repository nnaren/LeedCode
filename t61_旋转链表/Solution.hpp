#include <iostream>
#include "../ListNode.h"
#include <vector>
using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k ==0)
            return head;
        ListNode* cur = head;
        ListNode* last;
        int n = 0;
        while (cur) {
            last = cur;
            cur = cur->next;
            n++;
        }
        //成环
        last -> next = head;
        int t = n - (k % n) - 1;
        for(int i = 0; i < t; i++) { 
            head = head->next;
        }
        // 新头
        ListNode* newHead = head->next;
        // 新尾
        head->next = nullptr;
        return newHead;
    }
};