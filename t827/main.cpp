#include <iostream>
#include "Solution.hpp"

int main() {
    vector<vector<int>> grid = {{1, 1}, {1, 0}};
    Solution sol;
    cout << sol.largestIsland(grid) << endl;
    return 0;
}
