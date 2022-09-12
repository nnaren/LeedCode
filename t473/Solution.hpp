#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = 0;
        for (int i = 0; i < n;i++) {
            sum += matchsticks[i];
        }
        if (sum % 4 != 0) {
            return false;
        }      
        sort(matchsticks.begin(), matchsticks.end(),greater<int>());
        vector<int> edgeSum(4);
        return dfs(matchsticks, 0, sum/4, edgeSum);
    }


    bool dfs(vector<int>& matchsticks, int step , int len, vector<int>& edgeSum) {
        if(step == matchsticks.size()) {
            return true;
        }
        for(int  i = 0; i < 4 ; i++) {
            edgeSum[i] += matchsticks[step];
            if(edgeSum[i] <= len && dfs(matchsticks, step+1, len, edgeSum)) {
                return true;
            }
            edgeSum[i] -= matchsticks[step];
        }
        return false;

    }
};