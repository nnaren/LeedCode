//
// Created by Percy on 2021/10/23.
//

#ifndef T78_SOLUTION_H
#define T78_SOLUTION_H
#include <vector>
using namespace std;
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> path;
        dps(nums, 0, path);
        return res;
    }

    void dps(vector<int>& nums, int step,vector<int>& path)
    {
        if(step == nums.size())
        {
            res.push_back(path);
            for (auto item: path) {
                cout << item;
            }
            cout << endl;
            return;
        }
        dps(nums, step+1, path);

        path.push_back(nums[step]);
        dps(nums, step+1, path);
        path.pop_back();
    }
};
#endif //T78_SOLUTION_H
