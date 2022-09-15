#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    string s = "a";
    string p = ".*";
    Solution sol;
    sol.isMatch(s, p);
    if(sol.isMatchByRecursion(s, p)) {
        cout << "yes" << std::endl;
    } else {
        cout << "no" << std::endl;
    }
    return 0;
}
