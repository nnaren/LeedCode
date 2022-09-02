#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution sol;
    vector<vector<int>> people {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    sol.reconstructQueue(people);
    return 0;
}
