#include <iostream>
#include "Solution.hpp"

int main() {
    Solution sol;
    vector<int> arr {11,81,94,43,3};
    cout << sol.sumSubarrayMins(arr) << endl;
    return 0;
}
