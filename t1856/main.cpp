#include <iostream>
#include "Solution.hpp"

int main() {
    vector<int> nums {3,1,5,6,4,2};
    Solution sol;
    cout << sol.maxSumMinProduct(nums) << endl;
    return 0;
}
