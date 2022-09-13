#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string num_s = to_string(num);
        int n = num_s.length();
        int maxIndex = n;
        int index1 = -1;
        int index2 = -1;
        for(int i = n-1; i>=0; i--) {
            if(num_s[i] > num_s[maxIndex]) {
                maxIndex = i; 
            } else if (num_s[i] < num_s[maxIndex]) { // 当前最高位 小于 后面最大值：说明需要更换最高位和最大值
                index1 = i;  // 非最大的最高位
                index2 = maxIndex;  //  出去前面最高位的最大位
            }
        }
        if(index1 >=0) {
            swap(num_s[index1], num_s[index2]);
            return stoi(num_s);
        } else {
            return num;
        }
    }
};