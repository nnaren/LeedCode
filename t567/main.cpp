// 题目：567. 字符串的排列
// 难度：中等
// 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
// 换句话说，第一个字符串的排列之一是第二个字符串的 子串 。

// 示例 1：
// 输入: s1 = "ab" s2 = "eidbaooo"
// 输出: True
// 解释: s2 包含 s1 的排列之一 ("ba").

// 示例 2：
// 输入: s1= "ab" s2 = "eidboaoo"
// 输出: False

// 提示：
// 输入的字符串只包含小写字母
// 两个字符串的长度都在 [1, 10,000] 之间
#include"Solution.hpp"
int main()
{
    string s1 = "ab";
    string s2 = "eidboaoo";
    Solution slt;
    if(slt.checkInclusion(s1,s2))
    {
        cout << "ok" << endl;
    }
}
