
#include <stack>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int n = pushed.size();
        int popIndex = 0;
        for(int i = 0; i<n;i++){
            stk.emplace(pushed[i]);
            while(!stk.empty() && stk.top() == popped[popIndex]) {
                stk.pop();
                popIndex++;
            }
        }
        return stk.empty();
    }

    bool validateStackSequences2(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int n = pushed.size();
        int j = 0;
        for(int i = 0 ; i < n; ) {
            if(!stk.empty() && stk.top() == popped[j]) {
                stk.pop();
                cout << "pop";
                j++;
            }
            else if(pushed[i] == popped[j]) {
                j++; i++;
                cout << "ij";
            }  else {
                stk.push(pushed[i]);
                i++;
                cout << "push";
            }
        }
        while(!stk.empty() && stk.top() == popped[j]) {
            stk.pop();
            cout << "pop";
            j++;
        }
        return stk.empty();
    }
};