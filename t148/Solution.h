//
// Created by Percy on 2021/10/25.
//

#ifndef T148_SOLUTION_H
#define T148_SOLUTION_H

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        // 获得长度
        int len = 0;
        ListNode* node = head;
        while (node)
        {
            len++;
            node = node->next;
        }

        ListNode* dummyHead = new ListNode(0, head);
        for(int subLength = 1;subLength < len;subLength *=2)
        {
            ListNode* prev = dummyHead; // 用于merge后，连接一起。
            ListNode* cur = dummyHead->next;
            // 每组由2个subLength组成，直至到最后。
            while(cur) {
                ListNode* head1 = cur;
                //找到第二个head2
                for(int i = 1;  i<subLength && cur->next ;i++) {
                    cur = cur->next;
                }
                ListNode* head2 = cur->next;
                cur->next = nullptr; // head尾结点设置为nullptr
                cur = head2;
                // 将head2后面的尾结点设为nullptr
                for (int i = 1; i < subLength && cur && cur->next; i++) {
                    cur = cur->next;
                }
                ListNode* next = nullptr;  // 保存head2之后的头节点
                if(cur) //说明head2子链表后面还有节点
                {
                    next = cur->next;
                    cur->next = nullptr;
                }
                ListNode* merged = merge(head1,head2);
                prev->next = merged;  // 连接新的合并链表
                while (prev->next) {   // 移动到下个合并链表
                    prev = prev->next;
                }
                cur = next;  //恢复到原链表剩下的头链表
            }
        }
        return dummyHead->next;
    }
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }


};
#endif //T148_SOLUTION_H
