
// 题目：多重背包（bounded knapsack problem）
// 归类： 动态规划
// 与前面不同就是每种物品是有限个：一共有N种物品，
// 第i（i从1开始）种物品的数量为n[i]，重量为w[i]，价值为v[i]。
// 在总重量不超过背包承载上限W的情况下，能够装入背包的最大价值是多少？

#include "Solution.h"


int main()
{
    int w[6] = {1, 3, 7,  9, 3, 2};
    int v[6] = {2, 5, 6, 11, 7, 3};
    Solution solution;
    
    cout << solution.knapsack(w, v, 13, 6) << endl;
    return 0;
}