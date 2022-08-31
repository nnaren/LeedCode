// 654. 最大二叉树
// 给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:

// 创建一个根节点，其值为 nums 中的最大值。
// 递归地在最大值 左边 的 子数组前缀上 构建左子树。
// 递归地在最大值 右边 的 子数组后缀上 构建右子树。
// 返回 nums 构建的 最大二叉树 。

#include "Solution.hpp"
#include "../t654/Solution.hpp"
int main(){
    vector<int> nums {2,1,5,4};
    Solution sol;
    TreeNode* root = sol.constructMaximumBinaryTree(nums);
    PrintTree(root);
    Solution2 sol2;
    TreeNode* ans = sol2.insertIntoMaxTree(root, 3);
    PrintTree(ans);
    return 0;
}