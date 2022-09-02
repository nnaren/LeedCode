//
// Created by Percy on 2022/3/18.
//

#ifndef OFFER35_SOLUTION_H
#define OFFER35_SOLUTION_H
#include <unordered_set>
using namespace  std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    unordered_set<Node*> used;
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        if(!used.count(head))
        {
            Node* newNode = new Node(head->val);
            newNode->next = HeadcopyRandomList(head->next);
            newNode->random = copyRandomList(head->random);
        }
        return newNode;

    }

};


#endif //OFFER35_SOLUTION_H
