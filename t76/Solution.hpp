#include <unordered_map>
#include <iostream>
#include <string>
#include<limits.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char, int> need, window;
        for( char c: t)  need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        
        int start = 0, len = INT_MAX;
        while(right < s.size())
        {
            // c是将移入窗口的字符
            char c = s[right];
            // 左移窗口		
            right++;
            // 进行窗口内数据的一系列更新
            if(need.count(c))
            {
                window[c]++;
                if(window[c] == need[c])
                    valid++;
            }
            // debug 输出的位置
            cout << "Window : " << left << ", "<< right <<endl;

            // 判断左侧窗口是否要收缩
            while( valid ==  need.size())
            {
                if(right-left < len)
                {
                    start = left;
                    len = right-left;
                }
                // d是将移除窗口的字符
                char d = s[left];
                // 左移窗口
                left++;
                
                // 进行窗口内数据的一系列更新
                if(need.count(d))
                {
                    if(window[d] == need[d])
                        valid--;
                    window[d]--;
                }

            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);

    }
};