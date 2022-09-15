#include <iostream>
#include "Solution.hpp"

int main() {
    TreeNode* root = new TreeNode(3, 
                                  new TreeNode(4, new TreeNode(1), new TreeNode(2, new TreeNode(0), nullptr)),
                                  new TreeNode(5));
    TreeNode* subRoot = new TreeNode(4, new TreeNode(1), new TreeNode(2)); 
    Solution sol;
    if (sol.isSubtree(root, subRoot)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    if (sol.isSubtree2(root, subRoot)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
