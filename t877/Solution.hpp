#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // dp[i][j] 从(i - j) 赢对方的石子个数；  j>=i
        int dp[n][n];
        for(int i = 0 ; i <n;i++)
        {
            dp[i][i] = piles[i];
            
        }
        
        for (int j = 1; j < n; j++)
        {
            for(int i = j-1; i>=0; i--)
            {
                dp[i][j] = max( piles[j] - dp[i][j-1], piles[i] - dp[i+1][j]);
            }
        }
        if (dp[0][n-1]>0)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    int findIndex(int i, int j, int n)
    {
        int index = j;
        while (i>0)
        {
            index += (n+1-i);
            i--;
        }
        return index;
        
    }
    bool stoneGameDetail(vector<int>& piles) {
        int n = piles.size();
        // dp[i][j] 从(i - j) 赢对方的石子个数；  j>=i
        int dp[n][n];
        map<int, string> path;
        int index;
        for(int i = 0 ; i <n;i++)
        {
            dp[i][i] = piles[i];
            index = findIndex(i,i,n);
            path[index] =  to_string(i);
            cout << "(" << i << ", "<< i <<")  " << path[index] << endl;
        }
        
        for (int j = 1; j < n; j++)
        {
            for(int i = j-1; i>=0; i--)
            {
                if ( piles[j] - dp[i][j-1] >= piles[i] - dp[i+1][j] )
                {
                   
                    dp[i][j] = piles[j] - dp[i][j-1];
                    index = findIndex(i,j,n);
                    path[index] =  to_string(j) + " ==> " + path[index-1];
                    cout << "(" << i << ", "<< j <<")  " << path[index] << endl;
                }
                else
                {
                    dp[i][j] = piles[i] - dp[i+1][j];
                    index = findIndex(i,j,n);
                    path[index] = to_string(i) + " ==> " + path[index + (n-i)];
                    cout << "(" << i << ", "<< j <<")  " << path[index] << endl;
                }
            }
        }
        if (dp[0][n-1]>0)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};