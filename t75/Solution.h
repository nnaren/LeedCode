//
// Created by Percy on 2021/10/22.
//

#ifndef T75_SOLUTION_H
#define T75_SOLUTION_H
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> colors = {{0,0}, {1,0},{2,0}};
        for(int i=0; i < nums.size();i++)
        {

            if(nums[i] == 0)
            {
                swap( nums[i], nums[colors[0]]);

                if(nums[i] == 1)
                {
                    swap( nums[i], nums[colors[0]+colors[1]]);
                }
                colors[0] ++;
            } else if(nums[i] == 1)
            {
                swap( nums[i], nums[colors[0]+colors[1]]);
                colors[1] ++;
            } else{
                colors[2] ++;
            }

        }
    }
};
#endif //T75_SOLUTION_H
