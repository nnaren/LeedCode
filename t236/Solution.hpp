/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include"../tree_struct.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root == p || root == q)
        {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left!= nullptr && right !=nullptr)
        {
            return root;
        }

        if (left == nullptr && right == nullptr )
        {
            return nullptr;
        }
        
        return left == nullptr ? right:left;
    }

    TreeNode* lowestCommonAncestor(TreeNode * root , TreeNode *p , TreeNode *q) {
        dfs(root, p, q);
        return ans;
    }

    bool dfs(TreeNode * root, TreeNode *p , TreeNode *q){
        if(root == nullptr) {
            return false;
        }

        bool lchild = dfs(root->left, p, q);
        bool rchild = dfs(root->right, p, q);
        if((lchild && rchild) || ((root->val == p->val || root->val == q->val) && (lchild ||rchild)))
            ans = root;
        return lchild || rchild || (root->val == p->val || root->val == q->val);

    }
private: 
    TreeNode* ans;
};