#include <iostream>
#include <string>
#include <vector>
#include "../tree_struct.h"
using namespace std;

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr) return 0;
        findUnivaluePathAfterOrder(root);
        return longestPath;

    } 

    int findUnivaluePathAfterOrder(TreeNode* root) {
        int left =0, right=0;
        if(root->left) {
            left = findUnivaluePathAfterOrder(root->left); 
            if (root->val == root->left->val) {
                left++;
            } else{
                left =0;
            }
        }
        if(root->right) {
            right =  findUnivaluePathAfterOrder(root->right); 
            if (root->val == root->right->val) {
                right++;
            } else {
                right =0;
            }
        }
        longestPath = max(left + right, longestPath);
        return left + right;
    }
    int longestPath =0;


};