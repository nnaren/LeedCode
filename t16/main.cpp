#include <iostream>
#include "Solution.hpp"

int main() {
    vector<int> nums = {1 , 1, 1, 1};
    int target = -100;
    Solution sol;
    cout << sol.threeSumClosest(nums, target);
    return 0;
}
