//
// Created by Percy on 2021/10/24.
//

#ifndef T114_SOLUTION_H
#define T114_SOLUTION_H
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* leftTreeLastNode = root->left;
        if(leftTreeLastNode != nullptr)
        {
            while (leftTreeLastNode->right != nullptr)
            {
                leftTreeLastNode = leftTreeLastNode->right;
            }
            leftTreeLastNode->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }

    }
};
#endif //T114_SOLUTION_H

class Solution2 {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        treeTraverse(root);
    }
    TreeNode* treeTraverse(TreeNode* root)
    {
        if(!root->left && !root->right)  //判断当前子节点为空还是节点为空
        {
            return root;
        }
        TreeNode *lastLeftNode = nullptr;
        TreeNode *lastRightNode = nullptr;
        if(root->left) {
            lastLeftNode = treeTraverse(root->left);
        }// 为什么要创造新函数，原始想法是找不到最后一个节点，
        if(root->right)
        {
            lastRightNode = treeTraverse(root->right);
        }

        if(lastLeftNode)
        {
            lastLeftNode->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        if(lastRightNode)
            return lastRightNode;
        else
            return lastLeftNode;
    }
};
