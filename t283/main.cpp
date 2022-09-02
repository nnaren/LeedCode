#include <iostream>

#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> nums {1,0};
    Solution sol;
    sol.moveZeroes(nums);
    return 0;
}
