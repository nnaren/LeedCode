//
// Created by Percy on 2021/10/28.
//

#ifndef T416_SOLUTION_H
#define T416_SOLUTION_H
#include <vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        if(n<2)
            return false;
        int sum=0;
        int maxV = 0;
        for(auto num: nums)
        {
            sum+=num;
            maxV = max(maxV,num);
        }
        if(sum%2==1)
        {
            return false;
        }
        int target = sum/2;
//        if(maxV>target)
//        {
//            return false;
//        }
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            for (int j = 1; j <= target; j++) {
                if (j >= num) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n-1][target];

    }
};
#endif //T416_SOLUTION_H
