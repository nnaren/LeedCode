#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        bool areAlmostEqual(string s1, string s2) {
            int notSameNum = 0;
            char s1c, s2c;
            for(int i=0; i<s1.size();i++ ){
                if(s1[i] != s2[i]) {
                    if(notSameNum == 2) return false;
                    if(notSameNum == 1) {
                        if(s1c != s2[i] || s2c != s1[i]) {
                            return false;
                        } else {
                            notSameNum++;
                            continue;
                        }
                    }
                    s1c = s1[i];
                    s2c = s2[i];
                    notSameNum++;
                }
            }
            return notSameNum!=1;
    }
};