#include <iostream>
#include <unordered_set>
#include <vector>
#include <numeric>
using namespace std;
/*
// 灯泡分类： 
// 1 开关 1 2        1 2 3 4 5 6
// 2开关 2 4           2   4   6
// 3    1 3         1   3   5
// 4   1 4 7  3K+1  1     4  周期为6
    分四类：
    1   ：  1、3、4      控制
    2, 6：  1、2        控制
    3, 5：  1 3        控制
    4   ：  1， 2， 4   控制
    按压分配：
*/
class Solution {
public:
    int flipLights(int n, int presses) {
        unordered_set<int> seen;
        for (int i = 0; i < 1 << 4; i++) {
            vector<int> pressArr(4);
            // 怎么设计全排列  2进制 bitmap  pressArr[0] [1] [2] [3]
            //                                     1   1   0   1
            for (int j = 0; j < 4; j++) {
                pressArr[j] = (i >> j) & 1;
            }
            // ”1“的个数
            int sum = accumulate(pressArr.begin(), pressArr.end(), 0);
            if (sum % 2 == presses % 2 && sum <= presses) {
                int status = pressArr[0] ^ pressArr[1] ^ pressArr[3];
                if (n >= 2) {
                    status |= (pressArr[0] ^ pressArr[1]) << 1;
                }
                if (n >= 3) {
                    status |= (pressArr[0] ^ pressArr[2]) << 2;
                }
                if (n >= 4) {
                    status |= (pressArr[0] ^ pressArr[1] ^ pressArr[3]) << 3;
                }
                seen.emplace(status);
            }
        }
        return seen.size();
    }
};


