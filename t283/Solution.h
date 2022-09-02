//
// Created by Percy on 2021/10/27.
//

#ifndef T283_SOLUTION_H
#define T283_SOLUTION_H
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r=0;
        int n = nums.size();

        while(r<n)
        {
            if(nums[r])
            {
                if(r!=l)
                    swap(nums[r], nums[l]);
                l++;
            }
            r++;
        }
    }
};
#endif //T283_SOLUTION_H
