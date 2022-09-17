#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> first;
        int maxLenSubStr=-1;
        for(int i=0; i < s.size();i++) {
            if(first.find(s[i]) == first.end()) {
                first[s[i]] = i;
            } else {
                maxLenSubStr = max(maxLenSubStr, i-first[s[i]]-1);
            }
        }
        return maxLenSubStr;
    }
};