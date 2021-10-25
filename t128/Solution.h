//
// Created by Percy on 2021/10/25.
//

#ifndef T128_SOLUTION_H
#define T128_SOLUTION_H
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsInSet;
        for (auto i: nums) {
            numsInSet.insert(i);
        }

        int ans =0;
        for (auto i: nums) {
            if(!numsInSet.count(i-1))
            {
                int tempMax = 1;
                int num = i;
                while(numsInSet.count(num++))
                {
                    tempMax++;
                }
                ans = max(ans, tempMax);
            }

        }
        return ans;
    }
};
#endif //T128_SOLUTION_H
