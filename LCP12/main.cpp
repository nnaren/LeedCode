#include <iostream>
#include "Solution.hpp"

int main() {
    // vector<int> time = {1,2,3,3}; 
    int m = 2;
    
    vector<int> time = {50,47,68,33,35,84,25,49,91,75};
    Solution sol;
    cout << sol.minTime(time, 1) << endl;
    return 0;
}
