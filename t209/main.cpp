#include <iostream>
#include "Solution.hpp"

int main() {
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};
    Solution sol;
    cout << sol.minSubArrayLen(target, nums) << endl;

    return 0;
}
