#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k) {
            return 0;
        }
        unordered_set<char> has(s.begin(), s.end());
        unordered_map<char, int> counter;
        for (char c: s) {
            counter[c]++;
        }
        for (char c : has) {
            if(counter[c] < k) {
                vector<string> substrs;
                split(substrs, s, c);
                int res = 0;
                for(string substr : substrs) {
                    res = max(res, longestSubstring(substr, k));
                }
                return res;
            }
        }
        return s.size();
    }
    void split(vector<string> & substrs, string & s, const char c = ' ') {
        istringstream  iss(s);
        string temp;
        while(getline(iss, temp, c)) {
            substrs.push_back(temp);
        }
    }
};