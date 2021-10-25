#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
//
//    TreeNode *root = new TreeNode(1,
//                                  new TreeNode(2, new TreeNode(3), new TreeNode(4)),
//                                  new TreeNode(5, nullptr, new TreeNode(6)));
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);
    Solution2 Sol;
    Sol.flatten(root);
    return 0;
}
