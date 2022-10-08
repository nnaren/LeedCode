#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // 组合C(n, 2) = 1+2+3+...+n = n(n-1)
    // j - i == nums[j] - nums[i] 好数对 =>  nums[j] - j == num[i] - i 
    // 分类： nums[i] - i 为一类 
    // map 统计 每一类的个数
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = 1LL * n * (n - 1) / 2;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int t = nums[i] - i;
            ans -= mp[t];
            mp[t]++;
        }
        return ans;
    }
};