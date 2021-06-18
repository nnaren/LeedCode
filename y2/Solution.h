#include<iostream>

using namespace std;

class Solution {
public:
    static int knapsack(int w[], int v[],const int W,const int N) 
    {
        //dp[i][j]表示将前i种物品装进限重为j的背包可以获得的最大价值, 0<=i<N, 0<=j<W
        int  dp[N][W+1] ;

        //  第一列 0
        for (int i = 0; i < N; i++)
        {
            dp[i][0] = 0;
        }
        //  第一行 只有第0种物品
        for(int j=0; j<= W; j++)
        {
            dp[0][j] = (j / w[0]) * v[0];
        }
        // i: 总共0-i种  j:背包重量 j
        // 第二层种类加1个：j++
        // 不用第i种，dp[i][j] = dp[i-1][j]
        // 用第i种，dp[i][j] = dp[i][] + v[i]
        for(int i=1; i < N; i++)
        {
            cout  << "i: " << i;
            for (int j = 1; j < W+1; j++)
            {
                if(j >= w[i])
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-w[i]] + v[i]) ;
                    cout << " (j " << j << ") :" << dp[i][j] ;
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                    cout << " (j " << j << ") :" << dp[i][j] ;
                }

            }
            cout << endl;
            
        }
        
        return dp[5][13];
    }
    
};

