#include <iostream>
#include "../tree_struct.h"

using namespace std;

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr)
            return nullptr;
        if(root->val< low) {
            return trimBST(root->right, low, high);
        } else if (root->val > high) {
            return trimBST(root->left, low, high);
        } else {
            if(root->left!= nullptr) {
                root->left = trimBST(root->left, low, high);
            }
            if(root->right!= nullptr) {
                root->right = trimBST(root->right, low, high);
            }
            return root;
        }

        
    }
};