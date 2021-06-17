#include <vector>
#include <iostream>
#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;
class Solution {
public:
    // 方法一：前缀和 & 哈希表
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        hash_map<int,int> preSum;
        preSum[0] = 1; 
        int res = 0;
        int curSum = 0;
        for (int i = 0; i < n; i++)
        {
            cout << "index: " << i << " num: "<< nums[i] ;
            curSum += nums[i];
            int findSum = curSum - k;
            cout << "curSum: " << curSum << " find: " << findSum ;
            if(preSum.count(findSum))
            {
                cout << ". found: + " << preSum[findSum] ;
                res += preSum[findSum];
            }
            if(preSum.count(curSum))
            {
                preSum[curSum] = preSum[curSum]+1;
                cout << ". change Map: (" << curSum << ", " << preSum[curSum] << ")" << endl;
            }
            else
            {
                preSum[curSum] = 1;
                cout << ". add Map: (" << curSum << ", 1)" << endl;
            }
        }
        return res;
    }
    // 方法二：前缀和
    int subarraySum2(vector<int>& nums, int k) {
        int n = nums.size();

        int* sum = new int[n+1];
        sum[0] = 0;
        for (int i = 0; i < n; i++)
        {
            sum[i+1] = sum[i]+ nums[i];
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if( (sum[i]-sum[j]) == k )
                {
                    res++;
                    cout << "strat:" << j << "  end:" << i-1 <<endl;
                }
            }
        }
        return res;
    }

    
};