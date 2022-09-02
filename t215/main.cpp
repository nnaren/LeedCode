#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<int> nums { 3,2,1,5,6,4};
    Solution sol;
    sol.findKthLargest(nums,2);
    return 0;
}
