//
// Created by Percy on 2021/10/29.
//

#ifndef T309_SOLUTION_H
#define T309_SOLUTION_H
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3,0))  ;  // 2表示没有票,昨天刚卖冷冻期，1表示没有票非冷冻期，0表示有票
        dp[0][0] = -prices[1];
        dp[0][1] = 0;
        dp[0][2] = 0;
        for(int i=1;i < n;i++)
        {
            dp[i][0] =  max(dp[i-1][1]-prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][2],dp[i-1][1]);
            dp[i][2] = dp[i-1][0]+prices[i];
        }
        int res = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
        return res;
    }
};
#endif //T309_SOLUTION_H
