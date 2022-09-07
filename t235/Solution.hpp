#include <iostream>
#include "../tree_struct.h"
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if((root->val - p->val) * (root->val - q->val) <= 0 )
            {
                return root;
            } else if(root->val > p->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return root;
        
    }
};