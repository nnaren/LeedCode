#include<string>
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        string res;
        for (int i = 0; i < len; i++)
        {
            string  s1 = palingdrome(s, i, i);
            string  s2 = palingdrome(s, i, i+1);
            res = res.length() > s1.length() ?  res : s1;
            res = res.length() > s2.length() ?  res : s2;
        }
        return res;
        
    }

    string palingdrome(string& s, int l, int r)
    {
        while (l>=0 && r<s.length() && s[l]==s[r] && s[l] == s[r])
        {
            l--; r++;
        }
        return s.substr(l+1, r-1-l);
    }
};