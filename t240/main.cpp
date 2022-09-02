#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<vector<int>> matrix   = {{1,1}};
//    {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 2;
    Solution sol;
    sol.searchMatrix(matrix, target);

    return 0;
}
