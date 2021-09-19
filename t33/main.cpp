// 搜索旋转排序数组

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