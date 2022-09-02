#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        string temp;
        vector<int> nums;
        string sign;
        for(auto & c:expression) {
            if(c == '+' || c == '-' || c=='*') {
                sign += c;
                int curNum = atoi(temp.c_str());
                cout << curNum << endl;
                nums.push_back(curNum);
                temp = "";
            } else {
                temp += c;
            }
        }
        nums.push_back(atoi(temp.c_str()));

        int n  = nums.size();
        vector<vector<vector<int>>> dp (n, vector<vector<int>>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i].push_back( nums[i]);
        }
        for(int i = 1; i < n ; i++) {
            for(int j = 0; j < n-i ; j++) {
                int l = j;
                int r = j+i;
                cout << "(" << l << ", " << r << ")" << endl;
                for(int k = 0; k<i; k++) {
                    auto left = dp[l][l+k];
                    auto right = dp[l+k+1][r];
                    for (auto &  num1: left) {
                        for(auto & num2: right) {
                            if(sign[l+k] == '+') {
                                cout << num1 + num2 << endl;
                                dp[l][r].push_back(num1 + num2);
                            }
                            if(sign[l+k] == '-') {
                                cout << num1 - num2 << endl;
                                dp[l][r].push_back(num1 - num2);
                            }
                            if(sign[l+k] == '*') {
                                cout << num1 * num2 << endl;
                                dp[l][r].push_back(num1 * num2);
                            }
                            
                        }
                    }
                }      
                

            }
        }
        
        return dp[0][n-1];
    }
};