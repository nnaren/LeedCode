#include <iostream>
#include "Solution.hpp"
#include "../show.hpp"
int main() {
    Solution sol;
    vector<int> nums{1,2,3,4};
    show(sol.exchange(nums));
    return 0;
}
