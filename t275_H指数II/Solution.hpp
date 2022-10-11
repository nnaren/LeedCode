#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n-1;
        // 肯定在中间收敛 left=right=mid 如果也满足，那么结果为mid=left(right：mid-1不正确)，如果不满足，结果为left：mid+1
        while(left <= right) { 
            int mid = (left + right) / 2;
            cout << left << "," << mid << "," << right <<endl;
            if(citations[mid] >= n-mid) {
                right = mid-1;
                
            } else {
                left = mid+1;
            }
        }
        return n - left;
    }
};