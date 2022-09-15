#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    //「自底向上」动态规划
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

    // 至上而下的记忆化搜索
    const int ADDITION = -1;
    const int SUBTRACTION = -2;
    const int MULTIPLICATION = -3;

    vector<int> dfs(vector<vector<vector<int>>>& dp, int l, int r, const vector<int>& ops) {
        if (dp[l][r].empty()) {
            if (l == r) {
                dp[l][r].push_back(ops[l]);
            } else {
                for (int i = l; i < r; i += 2) {
                    auto left = dfs(dp, l, i, ops);
                    auto right = dfs(dp, i + 2, r, ops);
                    for (auto& lv : left) {
                        for (auto& rv : right) {
                            if (ops[i + 1] == ADDITION) {
                                dp[l][r].push_back(lv + rv);
                            } else if (ops[i + 1] == SUBTRACTION) {
                                dp[l][r].push_back(lv - rv);
                            } else {
                                dp[l][r].push_back(lv * rv);
                            }
                        }
                    }
                }
            }
        }
        return dp[l][r];
    }

    vector<int> diffWaysToCompute2(string expression) {
        vector<int> ops;
        for (int i = 0; i < expression.size();) {
            if (!isdigit(expression[i])) {
                if (expression[i] == '+') {
                    ops.push_back(ADDITION);
                } else if (expression[i] == '-') {
                    ops.push_back(SUBTRACTION);
                } else {
                    ops.push_back(MULTIPLICATION);
                }
                i++;
            } else {
                int t = 0;
                while (i < expression.size() && isdigit(expression[i])) {
                    t = t * 10 + expression[i] - '0';
                    i++;
                }
                ops.push_back(t);
            }
        }
        vector<vector<vector<int>>> dp((int) ops.size(), vector<vector<int>>((int) ops.size()));
        return dfs(dp, 0, ops.size() - 1, ops);
    }

};