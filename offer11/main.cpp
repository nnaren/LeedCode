// 搜索旋转排序数组
// 剑指 Offer 11. 旋转数组的最小数字
// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
// 例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

// 示例 1：

// 输入：[3,4,5,1,2]
// 输出：1
// 示例 2：

// 输入：[2,2,2,0,1]
// 输出：0

#include"Solution.hpp"

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout <<  Solution::search(nums, 0) << endl;
    vector<int> nums2 = {3, 4, 5, 6, 7, 0, 1, 2};
    cout << Solution::search(nums2, 0) << endl;

    vector<int> nums3 = {3, 4, 5, 6, 7, 0, 0, 0, 0, 1, 1, 2};
    cout << Solution::search(nums3, 0) << endl;

    vector<int> nums4 = {3, 1, 1};
    cout << Solution::search(nums4, 0) << endl;
    vector<int> nums5 = {3, 3, 1, 3};
    cout << Solution::search(nums5, 0) << endl;
    vector<int> nums6 = {10, 10, 10, 1, 10};
    cout << Solution::search(nums6, 0) << endl;
}