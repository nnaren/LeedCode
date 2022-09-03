#include <iostream>
#include "Solution.hpp"

int main() {
    // TreeNode* root = new TreeNode(1, new TreeNode(4, new TreeNode(4), new TreeNode(4)), new TreeNode(5, nullptr, new TreeNode(5)));
    TreeNode* root = new TreeNode(1, nullptr, new TreeNode(1, nullptr, new TreeNode(5)));

    Solution sol;
    cout << sol.longestUnivaluePath(root);
    return 0;
}
