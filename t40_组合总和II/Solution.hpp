#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include "../show.hpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
       
        ta = target;
        dfs(candidates, 0, 0);
        return ans;
    }

    void dfs (vector<int>& candidates, int step, int sum) {
        if(sum == ta) {
            
            ans.push_back(c);

            return;
        }
        if(step == candidates.size()) {
            return;
        }
        for(int i = step; i < candidates.size(); i++ ) {
            if(i>step && candidates[i-1]==candidates[i])
            continue;
            int curSum = sum + candidates[i];
            if(curSum > ta) {
                
                break;
            }
                
            c.push_back(candidates[i]);
            dfs(candidates, i+1, curSum);
            c.pop_back();
        }
        
    };

    vector<vector<int>> ans;
    vector<int> c;
    int ta ;
};