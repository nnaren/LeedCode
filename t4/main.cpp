#include <iostream>
#include "Solution.h"
int main() {
    std::vector<int > nums1  {1,2};
    std::vector<int > nums2  {3,4};
    Solution sol;
    cout << sol.findMedianSortedArrays(nums1, nums2);
    return 0;
}
