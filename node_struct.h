#ifndef __LIST_NODE__
#define __LIST_NODE__
// Definition for a Node.
#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
    }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void PrintListNode(ListNode * nodes) {
    while(nodes) {
        cout << nodes->val << endl;
        nodes = nodes->next;
    }
}

#endif
