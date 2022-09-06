#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int mod = 1000000007 ;
        int n = nums.size();

        stack<int> stackLeft;
        vector<int> left(n);  // 左边都大于或者等于
        for(int i = 0; i < n; i++)
        {
            while(!stackLeft.empty() && nums[i] <= nums[stackLeft.top()]){  // 单调栈递增 
                stackLeft.pop();
            }
            left[i] = stackLeft.empty() ? -1 : stackLeft.top();
            stackLeft.push(i);
        }

        stack<int> stackRight;
        vector<int> right(n);  // 右边都大于
        for(int i = n-1; i >=0 ; i--)
        {
            while(!stackRight.empty() && nums[i] <= nums[stackRight.top()]){
                stackRight.pop();
            }
            right[i] = stackRight.empty() ? n : stackRight.top();
            stackRight.push(i);
        }
        
        // 前缀和
        vector<long long> pre(n+1);
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i-1] + nums[i-1];
        }
        long long best = 0;
        for (int i = 0; i < n; ++i) {
            best = max(best, (pre[right[i] ] - pre[left[i]+1]) * nums[i]);
        }
        return best % mod;


    }

    int maxSumMinProduct2(vector<int>& nums) {
        int mod = 1000000007 ;
        int n = nums.size();

        stack<int> stackLeft;
        vector<int> left(n);  // 左边都大于或者等于
        for(int i = 0; i < n; i++)
        {
            while(!stackLeft.empty() && nums[i] <= nums[stackLeft.top()]){  // 单调栈递增 
                stackLeft.pop();
            }
            left[i] = stackLeft.empty() ? -1 : stackLeft.top();
            stackLeft.push(i);
        }

        stack<int> stackRight;
        vector<int> right(n);  // 右边都大于
        for(int i = n-1; i >=0 ; i--)
        {
            while(!stackRight.empty() && nums[i] <= nums[stackRight.top()]){
                stackRight.pop();
            }
            right[i] = stackRight.empty() ? n : stackRight.top();
            stackRight.push(i);
        }
        long long  ans=0;
        for (int i = 0; i < n; i++)
        {
            long long sum = 0;
            for(int j = left[i]+1; j<right[i]; j++) {   // 超时
                sum += nums[j];
            }

            ans = max(ans,  (sum*nums[i])  );
        }
        return ans % mod;
    }
};