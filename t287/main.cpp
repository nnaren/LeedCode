#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> nums = {3,1,3,4,2};
    Solution sol;
    sol.findDuplicate(nums);
    return 0;
}
