#include <iostream>
#include "Solution.hpp"

int main() {
    Solution sol;
    vector<int> time {2, 3, 2};
    vector<vector<int>> fruits {{0,2},{1,4},{2,1}};

    cout << sol.getMinimumTime(time, fruits, 3);
    return 0;
}
