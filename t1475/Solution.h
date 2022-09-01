//
// Created by Percy on 2021/10/21.
//

#ifndef T1475_SOLUTION_H
#define T1475_SOLUTION_H

#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i= n-1; i>=0 ; i--) {
            while ((!st.empty()) && st.top() > prices[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? prices[i] : prices[i] - st.top();
            st.emplace(prices[i]);
            
        } 
        return ans;
    }
};
    
#endif // T1475_SOLUTION_H