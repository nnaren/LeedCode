#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        // 在列方向进行二分查找，确定峰值所在行
        int low = 0;
        int high = m - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            // 获取mid行最大值的下标
            int maxIndex = max_element(mat[mid].begin(),mat[mid].end()) - mat[mid].begin();
            // 比下方的值小，下方一定存在峰值
            if (mat[mid][maxIndex] < mat[mid + 1][maxIndex]) {
                low = mid + 1;
            } else {
                high = mid; // 峰值是本身或在上方
            }
        }
        // 找到峰值所在行，再确定这一行的最大值
        int maxIndex = max_element(mat[low].begin(),mat[low].end()) - mat[low].begin();
        return {low, maxIndex};
    }
};
