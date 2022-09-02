#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    string s = "aa";
    string p = "a*";
    Solution sol;
    sol.isMatch(s, p);
    return 0;
}
