//
// Created by Percy on 2021/11/1.
//
/*
// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

 '.' 匹配任意单个字符
 '*' 匹配零个或多个前面的那一个元素
 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

*/

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
    // 放弃 ！！！ 不归路！
    bool isMatchByRecursion(string s, string p) {
        sLen = s.length();
        pLen = p.length();
        return match(s, p, 0, 0);
    }
    bool match(string s, string p, int i, int j) {
        if(i == sLen) {
            if(pLen-j>=2 && p[j+1]=='*') {
                return (  match(s,p,i,j+2));
            }
            return j == pLen || (p[j]=='*' && match(s,p,i-1,j+1)) ||  (p[j]=='*' && p[j-1]=='.' && match(s,p,i,j+1));
            // return i == sLen;
        } else if(j == pLen) {
            return i == sLen;
        } else if (p[j] == '.') {
            return (i < sLen) && match(s, p, i+1, j+1);
        } else if (p[j] != '*' && s[i] != p[j]) {
            if(j < pLen-1 && p[j+1] == '*') {
                return match(s, p, i, j+2);
            }    
        } else if(p[j] == '*') {  // 两种情况 ： s[i-1] == p[j-1] 和 p[j-1] =='.'
            if(s[i-1] == p[j-1]) {
                return  (s[i-1] == s[i] && match(s, p, i+1, j+1)) || match(s, p, i, j+1);
            } 
            if(p[j-1] =='.') {
                bool res = false;
                for(int t=0; t<=sLen - i;t++)
                    res |= match(s, p, i+t, j+1);
                return res;
            }
            // return (s[i-1] == p[j-1] || p[j-1] =='.') && (match(s, p, i, j+1));  // 
        } else {
            // bool res2 = false;
            // for(int t=0; (t<sLen - i) && s[i+t] == s[i];t++)
            //     res2 |= match(s, p, i+t, j+1);
            // return res2;
            return (s[i] == p[j]) && match(s, p, i+1, j+1);
        }
        return false;
    }
int sLen;
int pLen;

};

#endif //T10_SOLUTION_H
