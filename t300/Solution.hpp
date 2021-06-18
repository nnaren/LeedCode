#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int len = nums.size();
        int dp[len]={1,};

        
        for(int i=1; i<len; i++)
        {
            int maxNums = 0;
            for(int j=0;j<i;j++)
            {
                
                if(nums[i] > nums[j])
                {
                    maxNums = max(maxNums, dp[j]);
                }
            }
            dp[i] = maxNums+1;
            cout <<  dp[i] << "," << endl;
        }
        int result = 0;
        for(int i=0;i<len;i++)
        {
            result = max(result, dp[i]);
        }
        return result;
    }

   
        // Dynamic programming + Dichotomy.

    int lengthOfLIS2(vector<int> nums) 
    {
        int* tails = new int[nums.size()];
        int res = 0;
        for(int num : nums) {
            int i = 0, j = res;
            while(i < j) {
                int m = (i + j) / 2;
                if(tails[m] < num) i = m + 1;
                else j = m;
            }
            tails[i] = num;
            
            cout << endl;
            if(res == j) res++;
            for(int a=0 ;a<res;a++)
            cout << "tails:" << tails[a]  << "---" ;
            // cout << "teils:" << tails[i] << " res:" << res <<endl;
        }
        return res;
    }

    
};