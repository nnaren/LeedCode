#include<iostream>

using namespace std;

class Solution {
public:
    static int knapsack(int w[], int v[],const int W,const int N) 
    {
        //dp[i][j]表示将前i件物品装进限重为j的背包可以获得的最大价值, 0<=i<=N, 0<=j<=W
        const int nnn = N;
        const int www = W;
        int  dp[nnn+1][www+1] ;
        for (int j = 0; j < W+1; j++)
        {
            dp[0][j] = 0;
        }
        for(int i=1; i < N+1; i++)
        {
            cout  << "i: " << i;
            for (int j = 0; j < W+1; j++)
            {
                if(j >= w[i-1])
                {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1]) ;
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
        
        return dp[6][13];
    }
    
};

