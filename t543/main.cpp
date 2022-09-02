#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    TreeNode* root = new TreeNode(1,new TreeNode(2,new TreeNode(4),new TreeNode(5)),
                                  new TreeNode(3));
    Solution sol;
    sol.diameterOfBinaryTree(root);
//    TreeNode* root2 = new TreeNode(4,new TreeNode(-7),
//                                  new TreeNode(-3, new TreeNode(-9),new TreeNode(-3)));
//    {4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2}
//    createTree();
    return 0;
}

TreeNode createTree()
{

}

//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
