#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include "../show.hpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> visited(n);
        vector<int> track;
        function<void()> dfs = [&] () {
            if(track.size() == n) {
                // show(track);
                ans.push_back(track);
            }
            for(int i = 0; i<n; i++) {
                if(visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i - 1])) {
                    continue;
                }
                track.push_back(nums[i]);
                visited[i] = 1;
                dfs();
                track.pop_back();
                visited[i] = 0; 
            }
            
        };
        dfs();
        return ans;
    }
};