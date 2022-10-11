#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n-1;
        // 找区间 [0, ans) 左闭右开
        // 结果范围：0-n : 
        // 边界值0  0不满足，left不变
        // 边界值n n-1满足,左移到n
        // 肯定在中间收敛 left=right=mid 如果也满足，那么结果为mid=left(right：mid-1不正确)，如果不满足，结果为left：mid+1
        while(left <= right) { 
            int mid = (left + right) / 2;
            cout << left << "," << mid << "," << right <<endl;
            if(citations[mid] >= n-mid) {
                // 右移
                right = mid-1;
                
            } else { 
                // 左移
                left = mid+1;
            }
        }
        return n - left;
    }
};