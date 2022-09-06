#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, vector<int>> char2Index; 
        for(int i=0; i<s.length(); i++) {
            char2Index[s[i]].emplace_back(i);
        }
        int ans = 0;
        for(auto &&[ _, indexs] : char2Index) {
            indexs.insert(indexs.begin(), -1);
            indexs.emplace_back(s.length());
            for (int i = 1; i < indexs.size()-1; i++) {
                ans += (indexs[i]-indexs[i-1]) * (indexs[i+1] - indexs[i]);
            }
           
            

        }
        return ans;
    }
};