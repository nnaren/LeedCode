//
// Created by Percy on 2021/10/24.
//

#ifndef T101_SOLUTION_H
#define T101_SOLUTION_H


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
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right) {
            return true;
        }
        if(root->left && root->right && root->left->val == root->right->val)
        {
            return Recurse(root->left, root->right);
        } else {
            return false;
        }

    }
    bool Recurse(TreeNode* lTree, TreeNode* rTree)
    {
        bool result = true;
        if(!lTree->left && !rTree->right)
        {
            result &= true;
        } else if(lTree->left && rTree->right && lTree->left->val == rTree->right->val)
            result &= Recurse(lTree->left, rTree->right);
        else {
            return false;
        }
        if(!lTree->right && !rTree->left)
        {
            result &= true;
        }else if(lTree->right && rTree->left && lTree->right->val == rTree->left->val)
            result &= Recurse(lTree->right, rTree->left);
        else
        {
            return false;
        }
        return result;
    }
};

#endif //T101_SOLUTION_H
