//
// Created by Percy on 2021/10/27.
//

#ifndef T287_SOLUTION_H
#define T287_SOLUTION_H
#include <vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1;
        int r = n;
        while(l<r)
        {
            int m = (l+r)/2;
            int lessCnt=0;
            for(int i=0; i<n; i++)
            {
                if(nums[i]<=m)
                    lessCnt++;
            }
            if(lessCnt<=m)
            {
                l = m+1;
            } else {
                r = m-1;
            }

        }
        return r;
    }
};
#endif //T287_SOLUTION_H
