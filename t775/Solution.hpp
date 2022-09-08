#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int sec=0;
        int first= 0;
        for(int i=1; i<n; i++) {
            if(nums[i] < nums[i-1]) {
                if(nums[i] < sec) {
                    return false;
                }
                
                
                first = max(nums[i-1],first);
                sec = max(nums[i-1],first);
                
            } else {
                if(nums[i]<first)
                    return false;
                sec = max(nums[i-1],first);
                first = max(first,nums[i]);

            }
        }
        return true;
    }
};