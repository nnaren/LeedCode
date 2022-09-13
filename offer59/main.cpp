#include <iostream>
#include "Solution.hpp"
#include "../show.hpp"
int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution sol;
    vector<int> ans = sol.maxSlidingWindow(nums, k);
    show(ans);
    vector<int> ans2 = sol.maxSlidingWindow2(nums, k);
    show(ans2);
    return 0;
}
