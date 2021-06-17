// 方法一
// 滑动窗口 + set

#include <iostream>
#include <set>
#include <ext/hash_set>
using namespace std;

class Solution {
public:
// 方法一
// 滑动窗口 + 哈希表
// 左进右出，随时记录最值
    int lengthOfLongestSubstring(string s) {
        int maxStr=0;
        int n = s.size();
        if (n == 0)
        {
            return 0;
        }
        set<char> window;
        int left=0;
        for (int right = 0; right < n; right++)
        {
            while(window.find(s[right])!=window.end())
            {
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            maxStr = max(maxStr, right - left+1);
        }
        return maxStr;
    }

    int lengthOfLongestSubstring2(string s) {
        int maxStr=0;
        int n = s.size();
        if (n == 0)
        {
            return 0;
        }
        
        __gnu_cxx::hash_set<char> window;
        int left=0;
        for (int right = 0; right < n; right++)
        {
            while(window.find(s[right])!=window.end())
            {
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            maxStr = max(maxStr, right - left+1);
        }
        return maxStr;
    }
// 方法二
// 暴力
    int lengthOfLongestSubstring3(string s) {
        int n = s.length();
        if (n == 0)
        {
            return 0;
        }
        int result = 1;
        int left;
        for (int right = 1; right < n; right++)
        {
            
            for(left= right-1 ; left >=0; left--)
            {
                if(s.substr(left+1,right-left).find(s.at(left)) != string::npos)
                {
                    break;
                }
            }
            result = max(right-left, result);
        }
        return result;
    }
};