//
// Created by Percy on 2021/10/21.
//

#ifndef T282_SOLUTION_H
#define T282_SOLUTION_H

#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;
        int  num = s.size();
        vector<int> dp(num+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<num+1;i++) {
            
            int num = atoi(s.substr(i-2,2).c_str());
            if(s[i-1] == '0' && (s[i-2]!='1' && s[i-2]!='2'))
                return 0; 
            if(num == 10 || num == 20) {
               dp[i] = dp[i-2]; 
            }else if(num<=26 && num>10) {
                dp[i] = dp[i-1]+dp[i-2];
            }  else {
                dp[i] = dp[i-1];
            }
            
            
        }
        return dp[num];
    }
};
    
#endif //T282_SOLUTION_H
