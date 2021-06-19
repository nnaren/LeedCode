
// 题目：完全背包问题 
// 归类： 动态规划
// 一共有N种物品，每种物品有无限多个，第i（i从1开始）件物品的重量为w[i]，价值为v[i]。
// 在总重量不超过背包承载上限W的情况下，能够装入背包的最大价值是多少？

#include "Solution.h"


int main()
{
    int w[6] = {1, 3, 7,  9, 3, 2};
    int v[6] = {2, 5, 6, 11, 7, 3};
    Solution solution;
    
    cout << solution.knapsack(w, v, 13, 6) << endl;
    cout << "ok" << endl;
    return 0;
}