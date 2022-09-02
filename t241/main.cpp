#include <iostream>
#include "Solution.hpp"

int main() {
    Solution solution;
    
    vector<int > ans = solution.diffWaysToCompute("2*3-4*5");
    cout << "ans: " << endl;
    for (int a : ans) {
        cout << a << endl;
    }
    return 0;
}
