#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> nums{9,5};
    Solution sol;
    sol.canPartition(nums);
    return 0;
}
