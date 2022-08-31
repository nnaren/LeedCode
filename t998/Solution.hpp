#include "../tree_struct.h"
class Solution2 {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(!root) {
            return  new TreeNode(val);
        }
        if (root->val < val)
        {
            return  new TreeNode(val,root,nullptr);
 
        } else {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
 
        
    }
};