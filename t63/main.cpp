#include <iostream>
#include "Solution.h"

int main() {
    vector<vector<int>> obstacleGrid{{0,0,0},{0,1,0},{0,0,0}};
    Solution sol;
    int ans = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << ans << endl;
    return 0;

}