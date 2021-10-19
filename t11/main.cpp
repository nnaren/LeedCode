#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> ans {1,8,6,2,5,4,8,3,7};
    Solution sol;
    cout << sol.maxArea(ans) << endl;
    return 0;
}
