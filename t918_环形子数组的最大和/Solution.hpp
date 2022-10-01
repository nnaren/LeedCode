#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0], cur = nums[0];
        for (int i = 1; i < n; i++) {
            cur = nums[i] + max(cur, 0);
            ans = max(ans, cur);
        }
        // ans是单区间的子数组
        // 现在考虑所有双子数组
        // 对于每个i，我们想知道：在j>=i+2下，sum(num[j:])的最值。

        // 右区间的和 rightsums[i] = nums[i] + nums[i+1] + ... + nums[n-1]
        vector<int> rightSums(n);
        rightSums[n-1] = nums[n-1]; // n-1位置无法跨两个区间
        for (int i = n-2; i >= 0; i--) {
            rightSums[i] = rightSums[i+1] + nums[i]; 
        }
        
        
        vector<int> maxRight(n);  
        maxRight[n-1] = nums[n-1]; 
        for(int i = n-2; i >= 0; i--) {
            // 可选择i的情况下，最大右连续最大，以前最大或者包含i最大
            maxRight[i] = max(maxRight[i+1], rightSums[i]);

        }

        int leftSum = 0;
        for(int i = 0; i< n-2; i++) {
            leftSum += nums[i];
            ans = max(ans , leftSum + maxRight[i+2]);
        }
        return ans;
    }

    // 前缀和 与 单调队列
    int maxSubarraySumCircular2(vector<int>& nums) { 
        int n = nums.size();
        vector<int> preSumOfTwoNums (2*n+1, 0);
        // 计算前缀和
        for (int i = 0; i < 2*n ; i++) {
            // preSumOfTwoNums[i] ： 0到nums[i-1]
            preSumOfTwoNums[i+1] = preSumOfTwoNums[i] + nums[i%n];
        }
        deque<int> dq;
        int ans = nums[0];
        dq.push_back(0);
        for(int j = 1; j<=2*n ; j++) {
            if(dq.front() < j-n) {
                dq.pop_front();
            }
            ans = max(ans, preSumOfTwoNums[j] - preSumOfTwoNums[dq.front()]);
            // 单调递增
            while (!dq.empty() &&  preSumOfTwoNums[j] <= preSumOfTwoNums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(j);
        }
        return ans;
    }
};