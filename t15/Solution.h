//
// Created by Percy on 2021/10/19.
//

#ifndef T15_SOLUTION_H
#define T15_SOLUTION_H
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3)
            return ans;
        std::sort(nums.begin(), nums.end());
        for (auto item: nums) {
            cout << item << endl;
        }

        for(int first = 0 ;first < nums.size()-2; ++first )
        {
            if(first>0 && nums[first] == nums[first-1])
            {
                continue;
            }
            int target = - nums[first];
            int third = nums.size()-1;
            for (int second = first+1; second < nums.size()-1; ++second) {
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }

                while(second< third && nums[second] + nums[third] > target)
                {
                    third--;
                }
                if(second == third)
                {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                    cout << "Add: " << nums[first] << nums[second] << nums[third] << endl;
                }
            }


        }
        return ans;
    }
};

#endif //T15_SOLUTION_H
