#include "../ListNode.h"

class Solution {
public:
    static ListNode* deleteDuplicates(ListNode* head) 
    {
        
        if (head == nullptr)    return nullptr;
        ListNode* current = head;
        if(head->val != 0)
        {
            head = new ListNode(0, current);
        }
        else
        {
            head = new ListNode(1, current);
        }
        ListNode* before = head;

        int duplicate = 0;
        int curVar = current->val;
        

        while (current->next != nullptr)
        {
            if(curVar == current->next->val)
            {
                duplicate++;
            }
            else
            {
                if(duplicate >0)
                {
                    
                    duplicate = 0;
                    before->next = current->next;
                }
                else
                {
                    before = before->next; 
                }
            }
            current = current->next;
            curVar = current->val;
        }
        if(duplicate >0)
        {
            before->next = current->next;
        }
        return head->next;
    }
    static ListNode* deleteDuplicates2(ListNode* head) {
        //判断是否为空
        if(head==nullptr)
            return head;

        //head之前的伪头结点
        ListNode* prior_head = new ListNode(-1);
        prior_head->next = head;

        //用于return
        ListNode* my_head = prior_head;

        while(head && head->next){
            //如果出现值相同的情况
            if(head->val==head->next->val)
            {
                int val = head->val;
                //前进，直到值不相同
                while(head && head->val==val){
                    head=head->next;
                }
                //删除（跳过）中间的一堆值相同的节点
                prior_head->next = head;
            }
            //否则继续
            else{
                prior_head = prior_head->next;
                head = head->next;
            }
        }
        return my_head->next;
    }
    
};