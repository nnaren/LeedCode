#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution sol;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    sol.findDisappearedNumbers(nums);
    return 0;
}
