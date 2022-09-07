#include <iostream>
#include "Solution.hpp"

int main()
{
    TreeNode* root = new TreeNode(6,
                                  new TreeNode(2, new TreeNode(0), new TreeNode(4, new TreeNode(3), new TreeNode(5))),
                                  new TreeNode(8, new TreeNode(7), new TreeNode(9))
                                 );
    
    TreeNode* p = root->left;
    TreeNode* q = root->left->right->right;
    Solution sol;
    cout << sol.lowestCommonAncestor(root, p ,q)->val << endl;
    return 0;
}