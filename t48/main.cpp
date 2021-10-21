#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<vector<int>> nums = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    show(nums);
    Solution sol;
    sol.rotate(nums);
    show(nums);

    return 0;
}
