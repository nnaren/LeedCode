#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        int allSum = accumulate(nums.begin(), nums.end(),0);
        if( allSum%k != 0 ) return false;
        int target = allSum/k;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> sum(k);
        return dfs(nums, 0, k, target, sum);
    }
    bool dfs(vector<int>& nums, int step, int k, int target, vector<int>& sum) {
        if(step == n ) {
            return true;
        }
        for( int i = 0; i <k ; i++) {
            if(i && sum[i] == sum[i-1])   // 当前的值和上一轮一样，没必要继续， 剪枝
                continue;
            sum[i] += nums[step];
            if(sum[i] <= target && dfs(nums, step+1, k, target, sum)) {
                return true;
            }
            sum[i] -= nums[step];
        }
        return false;
    }
    int n;
};