#include <iostream>
#include "Solution.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    TreeNode root(4, new TreeNode(1, new TreeNode(0), new TreeNode(2, nullptr,new TreeNode(3) )),
                  new TreeNode(6,new TreeNode(5), new TreeNode(7, nullptr, new TreeNode(8) )));
    Solution sol;
    sol.convertBST(&root);

    return 0;
}
