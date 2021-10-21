//
// Created by Percy on 2021/10/21.
//

#ifndef T20_SOLUTION_H
#define T20_SOLUTION_H
#include <string>
#include <stack>
#include <unordered_map>
using  namespace  std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> map = {{']', '['}, {'}', '{'}, {')', '('}};
        for (char  c : s)
        {
            if(c=='(' || c== '[' || c== '{')
                st.push(c);
            else if (st.empty() || map[c] != st.top())
            {
                return false;
            } else {
                st.pop();
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};
#endif //T20_SOLUTION_H
