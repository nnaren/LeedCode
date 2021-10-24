//
// Created by Percy on 2021/10/24.
//

#ifndef T98_SOLUTION_H
#define T98_SOLUTION_H
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
    bool recurse(TreeNode* root, long lower, long upper)
    {
        bool result = true;
        if(root->left != nullptr)
        {
            if( root->left->val < root->val  && root->left->val> lower ){
                result &= recurse(root->left, lower, root->val);
            } else {
                return false;
            }
        }
        if(root->right != nullptr)
        {
            if( root->right->val > root->val  && root->left->val < upper){
                result &= recurse(root->right,root->val, upper);
            } else {
                return false;
            }
        }
        return result;
    }
    bool isValidBST(TreeNode* root) {
        return  recurse(root, LONG_MIN, LONG_MAX );

    }
};
#endif //T98_SOLUTION_H
