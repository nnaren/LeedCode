//
// Created by Percy on 2021/11/1.
//

#ifndef T10_SOLUTION_H
#define T10_SOLUTION_H
#include <string>
#include <vector>
using namespace  std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if(p[j-1] == '*')  // 匹配星号* ，要不星号取数为0，  要不星号取数不为0；
                {
                    dp[i][j] |= dp[i][j - 2];   // "a*" *取0时， p的前j个字符与p的前j-2字符一样。
                    if(i==0)
                        continue;
                    if(p[j - 2] == '.' || s[i-1] == p[j-2]) // .*组合 和匹配s的（前i-1）一样 或  t*组合 s最后一个字节和p倒数第二个字节一样
                        dp[i][j] |= dp[i-1][j];
                } else {
                    if(i==0)
                        continue;
                    if(p[j - 1] == '.' || s[i-1] == p[j-1])
                        dp[i][j] = dp[i-1][j-1];
                }

            }
        }
        return dp[m][n];
    }
};

#endif //T10_SOLUTION_H
