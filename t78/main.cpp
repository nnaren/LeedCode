#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> nums = {1,2,3};
    Solution sol;
    sol.subsets(nums);
    return 0;
}
