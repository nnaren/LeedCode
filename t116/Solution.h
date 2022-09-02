//
// Created by Percy on 2021/10/21.
//

#ifndef T1475_SOLUTION_H
#define T1475_SOLUTION_H

#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return nullptr;
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            // 记录当前队列大小
            int size = que.size();
            // 通过大小来遍历 当前层
            for(int i = 0; i < size; ++i) {
                Node* curNode = que.front();
                que.pop();
                if(i<size-1) {
                    curNode->next = que.front();
                }
                if(curNode->left) {
                    que.push(curNode->left);
                }
                if(curNode->right) {
                    que.push(curNode->right);
                }
            }

        }
        return root;
    }
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
#endif // T1475_SOLUTION_H