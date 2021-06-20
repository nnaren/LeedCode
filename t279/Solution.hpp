#include<iostream>
#include<limits.h>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        int jj=1; 
        for(int i = 2; i<=n ; i++)
        {
            int iMin = INT_MAX;
            for(int j =1;j*j<=i;j++)
            {
                iMin = min(dp[i-j*j], iMin);
                
                
            }
            dp[i] = iMin+1;
            cout << "index:" << i << ", dp:" << dp[i] << endl;
        }
        return dp[n];
    }
};