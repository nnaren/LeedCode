//
// Created by Percy on 2021/10/28.
//

#ifndef T448_SOLUTION_H
#define T448_SOLUTION_H
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            int x = (nums[i]-1)%n;
            nums[x]+=n;
        }
        for(int i =0;i<n;i++)
        {
            if(nums[i]<=n)
            {
                res.push_back(i+1);
            }
        }
        return res;
    }
};
#endif //T448_SOLUTION_H
