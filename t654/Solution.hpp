#include <vector>
#include <iostream>
#include "../tree_struct.h"
using namespace std;
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        return constructMaxTree(nums, 0, nums.size()-1);
    }

    TreeNode* constructMaxTree(vector<int>& nums, int left, int right) {
        if(left>right)
            return 0;
        int bigIndex = left;
        for(int i = left+1; i<=right; i++ ) {
            if(nums[bigIndex] < nums[i]) {
                
                bigIndex = i;
            }
        }
        cout << bigIndex << ":" <<nums[bigIndex]  <<endl;
        TreeNode* root = new TreeNode(nums[bigIndex] );
        root->left = constructMaxTree(nums, left, bigIndex-1);
        root->right = constructMaxTree(nums, bigIndex+1, right);
        return root;
    }
};