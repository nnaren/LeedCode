#include <iostream>
#include <cstring>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        int siz = digits.size();
        memo.resize(siz, vector<vector<int>>(2, vector<int>(2, -1)));
        reverse(digits.begin(), digits.end());
        
        function<int(int, bool, bool)> dfs = [&](int pos, int  bound, int diff) -> int {
            // 边界值： 最后一层选择完了，确定 1或者 0；
            if (pos == digits.size()) {  
                return diff;
            }
            // 查备忘录，消去重复
            if (memo[pos][bound][diff] != -1) {
                return memo[pos][bound][diff];
            }
            // 更新备忘录的子问题：

            // 当前层的结果 等于下层之和
            int ret = 0; 
            // 下层的选择 ： （1)限制 ，小于等于 边界值 n （2）不限制 0，1， 
            for (int i = 0; i <= (bound ? digits[pos] : 9); ++i) {
                if (check[i] != -1) {
                    // 状态变化： 是否 还是bound,   是否加入了不同数字
                    int nextBound = 0, nextDiff = 0;
                    if((bound == 1) && (i == digits[pos])) {
                        nextBound = 1;
                    }
                    if((diff==1) || (check[i] == 1)) {
                        nextDiff = 1;
                    }
                    ret += dfs(pos + 1, nextBound, nextDiff);
                }
            }
            return memo[pos][bound][diff] = ret;
        };
        
        int ans = dfs(0, true, false);
        return ans;
    }

private:          /* 0, 1, 2,  3,  4, 5, 6,  7, 8, 9,  */
    int check[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1}; // 映射 -1 不可选
    vector<vector<vector<int>>> memo;
};
