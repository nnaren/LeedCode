#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    string str = "()[]{}";
    Solution sol;
    sol.isValid(str);
    return 0;
}
