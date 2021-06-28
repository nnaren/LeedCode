#include<vector>
#include <cstring>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int sz = nums.size();
        
        int points[sz+2];
        points[0] = 1;
        points[sz+1] = 1;
        for (int i = 1; i < sz+1; i++)
        {
            points[i] = nums[i-1];
        }

        int dp[sz+2][sz+2];
        memset(dp, 0 , sizeof(dp));
        for (int i = sz; i>=0; i--)
        {
            for(int j= i+1;j<sz+2;j++)
            {
                for (int k = i+1; k < j; k++)
                {
                    dp[i][j] = max(dp[i][j],
                                dp[i][k]+dp[k][j]+points[i]*points[k]*points[j]);
                }
                
            }
        }
        return dp[0][sz+1];
    }
};