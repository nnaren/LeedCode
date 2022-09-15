#include <iostream>
#include "Solution.hpp"

int main() {
   
    
    // int n = 6;
    // vector<vector<int>> connections = {{0,1}, {1,3}, {2,3}, {4,0},{4,5}};
    int n = 5;
    vector<vector<int>> connections = {{4,3},{2,3},{1,2},{1,0}};
    Solution sol;
    sol.minReorder(n, connections);
    return 0;
}
