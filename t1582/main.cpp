#include <iostream>
#include "Solution.hpp"

int main() {
//    vector<vector<int>> mat {{1, 0, 0},
//                             {0, 0, 1},
//                             {1, 0, 0}};
    vector<vector<int>> mat {{0,0,0,0,0,0,0,0},
                             {0,0,0,1,0,0,0,0},
                             {0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,1,0},
                             {0,1,0,0,0,0,1,0},
                             {0,1,0,0,0,0,0,0}};
    Solution sol;
    int ans = sol.numSpecial(mat);
    return 0;
}
