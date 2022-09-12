#include <iostream>
#include "Solution.hpp"

int main() {
    vector<int> quality = {10,20,5}, wage = {70,50,30};
    int k = 2;
    Solution sol;
    sol.mincostToHireWorkers(quality, wage, k);
    return 0;
}
