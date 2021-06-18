// T300. 
// 《最长递增子序列》
// 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

// 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
// 例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

// 提示：
// 1 <= nums.length <= 2500
// -10^4 <= nums[i] <= 10^4

// 示例 1：
// 输入：nums = [10,9,2,5,3,7,101,18]
// 输出：4
// 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
// 示例 2：
// 输入：nums = [0,1,0,3,2,3]
// 输出：4
// 示例 3：
// 输入：nums = [7,7,7,7,7,7,7]
// 输出：1
//  

#include <vector>
#include <iostream>
#include "Solution.hpp"
using namespace std;
int main()
{
    Solution solution;

    vector<int> case1 ={10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Calc1: " << endl;
    int result = solution.lengthOfLIS2(case1);
    cout << "case1: " << result << endl;

    vector<int> case2 ={10,20,30,40,50,13,14,35};
    cout << "Calc2: " << endl;
    int result2 = solution.lengthOfLIS2(case2);
    cout << "case2: " << result2 << endl;

    vector<int> case3 ={7,7,7,7,7,7,7};
    cout << "Calc3: " << endl;
    int result3 = solution.lengthOfLIS(case3);
    cout << "case3: " << result3 << endl;
    return 0;
}

