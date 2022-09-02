#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> nums{1,2,3,0,2};
    Solution sol;
    sol.maxProfit(nums);
    return 0;
}
