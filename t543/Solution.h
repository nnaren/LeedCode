//
// Created by Percy on 2021/10/29.
//

#ifndef T543_SOLUTION_H
#define T543_SOLUTION_H
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
    int res;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int leftnum = childTreeHeight(root->left);
        int rightnum = childTreeHeight(root->right);
        return max(res, leftnum+rightnum);
    }
    int childTreeHeight(TreeNode* root)
    {
        if(!root) return 0;
        int leftnum = childTreeHeight(root->left);
        int rightnum = childTreeHeight(root->right);
        int height = max(leftnum,rightnum)+1;
        res = max(res, leftnum+rightnum);
        return height;
    }
};
#endif //T543_SOLUTION_H
