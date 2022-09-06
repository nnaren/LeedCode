#include <iostream>
#include "Solution.hpp"

int main() {
    TreeNode* root = new TreeNode(1, 
                            new TreeNode(2, new TreeNode(4) ,nullptr),
                            new TreeNode(3, new TreeNode(2, new TreeNode(4),nullptr), new TreeNode(4))
                        );
    Solution sol;
    vector<TreeNode* > ans = sol.findDuplicateSubtrees(root);
    for(auto a : ans) {
        PrintTree(a);
        
    }
    return 0;
}
