// 654. 最大二叉树
// 给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:

// 创建一个根节点，其值为 nums 中的最大值。
// 递归地在最大值 左边 的 子数组前缀上 构建左子树。
// 递归地在最大值 右边 的 子数组后缀上 构建右子树。
// 返回 nums 构建的 最大二叉树 。
#include <vector>
#include <iostream>
#include "Solution.hpp"
using namespace std;
int main(){
    // vector<int> pushed {1, 2, 3, 4, 5};
    // vector<int> poped  {4, 5, 3, 2, 1};

    //     vector<int> pushed {1, 2, 3, 4, 5};
    // vector<int> poped  {4, 3, 5, 1, 2};

    vector<int> pushed {3, 0, 1, 2};
    vector<int> poped  {2, 3, 1, 0};
    Solution solution;
    if(solution.validateStackSequences(pushed, poped)) 
        std::cout << "ok";
    else
        std::cout << "false";
    return 0;
}