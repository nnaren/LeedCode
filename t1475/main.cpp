#include <iostream>
#include "Solution.h"

int main() {
    vector<int> prices {8, 4, 6, 2, 3};

    Solution sol;
    vector<int> ans = sol.finalPrices(prices);
    for(auto p : ans) {
        cout << p << endl;
    }

    return 0;
}
