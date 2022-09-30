#include <iostream>
#include <string>
#include <vector>
#include "../node_struct.h"
using namespace std;

class MyLinkedList {
public:
    MyLinkedList() {
        head = new ListNode();
        len = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= len)
            return -1;
        ListNode* cur = head;
        for(int i = 0; i <= index ; i++)
            cur = cur->next;
        
        return cur->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(len, val);
    }
    
    void addAtIndex(int index, int val) {
        ListNode* cur = head;
        if(index < 0) index = 0;
        if(index > len) return;
        ListNode* prev = head;
        for(int i = 0; i<index; i++) {
            prev = prev->next;
        }
        ListNode* node = new ListNode(val);
        node->next = node;
        swap(node->next, prev->next);
        len++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= 0 && index < len) {
            ListNode* prev = head;
            for(int i = 0; i<index; i++) {
                prev = prev->next;

            }
            prev->next = prev->next->next;
            len--;
        }
    }
    ListNode* head;
    int len;
};

