#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int  n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 1e9;
        for (int i = 0; i < n-2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i+1;
            int right = n-1;
            
             
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) {
                    return sum;
                }
                if(abs(ans-target)  > abs(sum-target)) {
                    ans = sum;
                }
                
                if( sum > target) {
                    int nextRight = right-1;
                    while (nextRight > left && nums[right]==nums[nextRight])
                    {
                        nextRight--;
                    }
                    right = nextRight;
                } else {
                    int nextLeft = left+1;
                    while (nextLeft < right && nums[nextLeft]==nums[left])
                    {
                        nextLeft++;
                    }
                    left = nextLeft;
                }
            }
            
        }
        return ans;
        
    }
};