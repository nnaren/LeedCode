#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int > nums = {5,7,7,8,8,10};
//    vector<int > nums = {2,2};
    Solution sol;
    sol.searchRange(nums, 8);
    return 0;
}
