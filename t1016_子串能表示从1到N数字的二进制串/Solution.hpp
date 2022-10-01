#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool queryString(string s, int n) {
        unordered_set<int> exits;
        for(int i = 0 ;i<s.size() ;i++) {
            if(s[i]=='0')
                continue;
            int num =0 ;
            for(int j = i ;j<s.size() ;j++) {
                num = (num << 1) +s[j]-'0';
                if(num > n) 
                    break;
                cout << "add:" << num <<endl;
                exits.insert(num);
            }
        }
        return (exits.size() == n);
    }
};