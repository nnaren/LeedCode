#include <iostream>
#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    // 重构： 左括号为0，右括号结算。先保存一个0，结算到前面的值
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (auto c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int v = st.top();
                st.pop();
                st.top() += max(2 * v, 1);
            }
        }
        return st.top();
    }
    // 左括号为-1，右括号结算
    int scoreOfParentheses_my(string s) {
        stack<int> st;
        for(auto & c : s) {
            if(c == '(') {
                st.push(-1);
            } else {
                int  cur = st.top();
                if(cur == -1){
                    st.pop();
                    st.push(1);
                    continue;
                }   
                int sum = 0;
                while(cur != -1) {
                    sum+= cur;
                    st.pop();
                    cur = st.top();
                }
                st.pop();
                st.push(sum *2);
            }
        }
        int ans = 0;
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};