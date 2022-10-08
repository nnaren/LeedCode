#include <iostream>
#include <numeric>
#include <vector>
#include "../show.hpp"
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> idx1(n), idx2(n);
        iota(idx1.begin(), idx1.end(), 0);
        iota(idx2.begin(), idx2.end(), 0);
        sort(idx1.begin(), idx1.end(), [&](int i, int j) { return nums1[i] < nums1[j]; });
        sort(idx2.begin(), idx2.end(), [&](int i, int j) { return nums2[i] < nums2[j]; });
        // 索引按nums值从小到大
        vector<int> ans(n);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; ++i) {
             // nums1 比 nums2 大 ，则当前为位置合适
            if (nums1[idx1[i]] > nums2[idx2[left]]) {
               
                ans[idx2[left]] = nums1[idx1[i]];
                ++left;
            }
            // nums1 比 nums2 等于或小 ，当前的位置不合适，对应nums2最大。原先的位置留着
            else {
                ans[idx2[right]] = nums1[idx1[i]];
                --right;
            }
        }
        return ans;
    }
};