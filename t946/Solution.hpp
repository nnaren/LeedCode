
#include <stack>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        // stk.push();
        for(int i = 0, j=0; j < popped.size(); ) {
            if(!stk.empty() && stk.top() == popped[j]) {
                stk.pop();
                j++;
            } else if(pushed[i] == popped[j]) {
                j++; i++;
            }
             else {
                if(i == pushed.size())
                    break;
                stk.push(pushed[i]);
                i++;
            }
        }
        return stk.empty();
    }
};