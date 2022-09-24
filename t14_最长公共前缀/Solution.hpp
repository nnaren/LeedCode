#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int minLen = 200;
        for(int i=0; i<n; i++) {
            int siz = strs[i].size();
            minLen = min(minLen, siz);
        }
        int ans = 0;
        int checkId;
        for(; ans <= minLen ;ans++) {
            char c = strs[0][ans];
            checkId = 1;
            for(; checkId < n; checkId++) {
                if(c != strs[checkId][ans])
                    break;
            }
            if(checkId < n) 
                break;

        }
        return strs[0].substr(0,ans);
    }
};