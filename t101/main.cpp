#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;

    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3),new TreeNode(4)),
                                  new TreeNode(2, new TreeNode(4),new TreeNode(3)));
    Solution sol;
    sol.isSymmetric(root);
    return 0;
}
