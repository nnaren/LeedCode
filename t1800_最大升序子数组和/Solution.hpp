#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=0;
        int curMax = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] <= nums[i-1]) {
                ans = max(curMax, ans);
                curMax = nums[i];
            } else {
                curMax += nums[i];
            }
        }
        ans = max(curMax, ans);
        return ans;
    }
};