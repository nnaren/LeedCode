#include <iostream>
#include "Solution.hpp"

int main() {
    vector<int> matchsticks = /*{3,3,3,3,4}*/ {2,2,2,2,2,6};
    Solution sol;
    if (sol.makesquare(matchsticks))
    {
        cout << "ok" << endl;
    }
    
    return 0;
}
