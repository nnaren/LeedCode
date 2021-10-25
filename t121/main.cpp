#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int > prices {7,1,5,3,6,4};
    Solution sol;
    sol.maxProfit(prices);

    return 0;
}
