#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution sol;
    std::vector<int> nums = {2,0,2,1,1,0};
    sol.sortColors(nums);
    return 0;
}
