#include <iostream>
#include "Solution.hpp"
#include "../show.hpp"

int main() {
    vector<vector<int>> nums   {{10,20,15},
                                {21,30,14},
                                { 7,16,32}};
    Solution sol;
    show(sol.findPeakGrid(nums));
    return 0;
}
