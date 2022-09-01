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
    vector<string> addOperators(string num, int target) {
        int numSize = num.length();
        vector<string> ans;

        function<void(int, string&, long, long)> backtrack = [&](int step, string& expr, long midRes, long mulResult) {
            if(step == numSize) {
                if(target == midRes) {
                    ans.emplace_back(expr);
                }
                return;
            }

            // expr :     ?符号  | 数字[step, right]   后面用 (+ - *)替代符号
            int signPlace = expr.size();
            if(step > 0) {
                expr.push_back('?');
            }
            long val = 0;
            for (int right = step; right < numSize && (right == step || num[step] != '0') ; ++right) {
                val = val*10 + num[right] - '0';
                expr.push_back(num[right]);
                if(step == 0) {
                    backtrack(right+1, expr, val, val);
                } else {
                    expr[signPlace] = '+';
                    backtrack(right+1, expr, midRes+val, val);

                    expr[signPlace] = '-';
                    backtrack(right+1, expr, midRes-val, -val);

                    expr[signPlace] = '*';
                    backtrack(right+1, expr, midRes-mulResult + mulResult*val, mulResult*val);

                }
            }
            expr.resize(signPlace);

        }; 

        string expr;
        backtrack(0, expr, 0, 0);
        return ans;

    }
    

};

    
#endif //T282_SOLUTION_H
