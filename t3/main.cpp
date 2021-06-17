
// 题目：无重复字符的最长子串
// 归类： 滑动窗口（方法一）
// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

#include<string>
#include<iostream>
#include "Solution.h"
using namespace std;


int main()
{
    string str1("abcabcbb");
    // string str1("au");
    // string str1("a123612345c"); 
    Solution solution;
    int result = solution.lengthOfLongestSubstring2(str1);
    cout << result << endl;
    return 0;
}