#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int m;
        //找某个值，一定在范围[0, n-1]
        //结束在l=r的情况
        // 
        while (l < r) {
            m = (l+r)/2;
            cout << l<<" "<<m<<" "<<r<< endl;
            if(nums[m] > nums[m+1]) {
                // 满足条件：结果在左边，右移， 只能移到m 不能移到m-1
                r = m;
            } else {
                // 不满足调节：在右边，左移
                l = m+1;
            }
        }
        return l;
    }
};