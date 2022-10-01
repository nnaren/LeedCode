#include <iostream>
#include "Solution.hpp"

int main() {
    // vector<int> postorder {1,3,2,6,5};
    vector<int> postorder {1,6,3,2,5};

    Solution sol;
    cout << sol.verifyPostorder2(postorder) << endl;
    return 0;
}
