#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int > preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7};
    Solution sol;
    sol.buildTree(preorder, inorder);
    return 0;
}
