#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        
        backtrack(nums, track);
        
        return result;
    }
    void backtrack(vector<int> nums, vector<int> track)
    {
        if (track.size() == nums.size())
        {
            result.push_back(*(new vector<int>(track)));
            return;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if(find(track.begin(), track.end(), nums[i]) != track.end())
            {
                continue;
            }
            track.push_back(nums[i]);
            backtrack(nums, track);
            track.pop_back();
        }
        
        return;
    }
private:
    vector<vector<int>> result;
};