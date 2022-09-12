#include <iostream>
#include "Solution.hpp"

int main() {
    vector<vector<int>>grid = { {0,0,0,0},
                                {1,0,1,0},
                                {0,1,1,0},
                                {0,0,0,0}};
    Solution sol;
    cout << sol.numEnclaves2(grid) << endl;
    return 0;
}
