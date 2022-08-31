#include <iostream>

#include "../tree_struct.h"
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        Node* first = head;
        while(first != nullptr) {
            cout << first->val << endl;
            Node* newNode = new Node(first->val);
            newNode->next = first->next;
            first->next = newNode;
            first = newNode->next;
        }
        Node* second = head;
        while (second != nullptr) {
            if(second->random !=nullptr) {
                second->next->random = second->random->next;
            } else {
                second->next->random = nullptr;
            }
            second = second->next->next;
        }
        Node* ans = head->next;
        while (head!=nullptr) {
            Node* temp = head->next;
            head->next = head->next->next;
            temp->next = ( temp->next != nullptr) ? head->next : nullptr;
            head = head->next;
        }
        
        return ans;
        
    }
};

