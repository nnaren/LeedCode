#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, end = 0;
        int ans = 1e9;
        int sum = 0;
        while (end < nums.size())
        {
            sum += nums[end];
            if(sum >= target) {
                while (start <= end)
                {
                    sum -= nums[start];
                    start++;
                    if(sum < target ) {
                        ans = min(ans, end-start);
                        break;
                    }
                    
                }
                
            }
            end++;
        }
        return ans;
    }
};