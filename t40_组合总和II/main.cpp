#include <iostream>
#include "Solution.hpp"

int main() {
    vector<int> candidates {10,1,2,7,6,1,5};
    int target = 8;
    Solution sol;
    sol.combinationSum2(candidates, target);
    return 0;
}
