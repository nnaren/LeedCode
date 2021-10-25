//
// Created by Percy on 2021/10/25.
//

#ifndef T139_SOLUTION_H
#define T139_SOLUTION_H
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1);

        unordered_set <string> wordDictSet;
        wordDictSet.insert(wordDict.begin(), wordDict.end());
        dp[0] =true;
        for(int i=1; i<=s.length();i++)
        {
            for(int j=0;j<i)
            {
                if(dp[j] && wordDictSet.count(s.substr( j, i-j))  )
                {
                    dp[i] = true;
                    break;
                }
            }


        }
        return dp[s.length()];
    }
};
#endif //T139_SOLUTION_H
