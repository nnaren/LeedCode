#include <iostream>
#include "Solution.hpp"

int main() {
    TreeNode * root = new TreeNode(8, new TreeNode(3), new TreeNode(10));
    Solution sol;
    cout << sol.maxAncestorDiff(root);
    return 0;
}
