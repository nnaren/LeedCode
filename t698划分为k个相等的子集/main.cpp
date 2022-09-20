#include <iostream>
#include "Solution.hpp"

int main() {
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    Solution sol;
    cout << sol.canPartitionKSubsets(nums, k );
    return 0;
}
