//
// Created by Percy on 2021/10/25.
//

#ifndef T121_SOLUTION_H
#define T121_SOLUTION_H
#include <vector>
#include <list>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        list<int> st;
        int ans=-1;
        prices.push_back(0);
        for(auto p : prices)
        {
            while(!st.empty() && p< st.back())
            {
                ans = max(ans, st.back() - st.front());
                st.pop_back();
            }
            st.push_back(p);
        }
        return ans;
    }
};
#endif //T121_SOLUTION_H
