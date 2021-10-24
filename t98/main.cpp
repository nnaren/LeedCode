#include <iostream>
#include "Solution.h"

int main()
{
    Solution sol;
//    TreeNode* root= new TreeNode(5,new TreeNode(4),new TreeNode(6,new TreeNode(3),new TreeNode(7)));
    TreeNode* root = new TreeNode(2,new TreeNode(1),  new TreeNode(3) );
    sol.isValidBST(root);
}
