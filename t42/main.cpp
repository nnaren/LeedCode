#include <iostream>
#include "Solution.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1 };
    Solution sol;
    sol.trap(height);
    return 0;
}
