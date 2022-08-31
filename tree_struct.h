#include <iostream>
#ifndef _TREE_NODE_
#define _TREE_NODE_

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void PrintTree(TreeNode * tree) {
    if(tree == nullptr) return;
    std::cout << tree->val << std::endl;
    PrintTree(tree->left);
    PrintTree(tree->right);
}
#endif