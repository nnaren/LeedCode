// 1293. 网格中的最短路径
// 给你一个 m * n 的网格，其中每个单元格不是 0（空）就是 1（障碍物）。
// 每一步，您都可以在空白单元格中上、下、左、右移动。

// 如果您 最多 可以消除 k 个障碍物，请找出从左上角 (0, 0) 到右下角 
// (m-1, n-1) 的最短路径，并返回通过该路径所需的步数。
// 如果找不到这样的路径，则返回 -1。

// 示例 1：
// 输入： 
// grid = 
// [[0,0,0],
//  [1,1,0],
//  [0,0,0],
//  [0,1,1],
//  [0,0,0]], 
// k = 1
// 输出：6
// 解释：
// 不消除任何障碍的最短路径是 10。
// 消除位置 (3,2) 处的障碍后，最短路径是 6 。该路径是 (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).

// 示例 2：
// 输入：
// grid = 
// [[0,1,1],
//  [1,1,1],
//  [1,0,0]], 
// k = 1
// 输出：-1
// 解释：
// 我们至少需要消除两个障碍才能找到这样的路径。

#include "Solution.hpp"

int main()
{
    // vector<vector<int>>grid = { {0,0,0}, {1,1,0}, {0,0,0}, {0,1,1}, {0,0,0} };
    // vector<vector<int>>grid = { {0,0,0} };
    vector<vector<int>>grid = 
       {{0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0,1,0,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,0,0,1,1},
        {1,0,0,1,0,1,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,0,1,0,0,1,1,0,0,1,0,1,0,1,1,0,1},
        {0,0,0,0,1,0,1,1,1,0,0,1,0,0,1,1,0,0,0,0,1,1,1,1,0,1,0,0,0,1,1,1,0,1,0,0,1},
        {1,1,0,1,1,0,1,0,0,1,1,0,1,0,0,0,0,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,0,0,1},
        {1,1,1,0,0,0,1,1,1,1,0,1,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,1,0,1,0},
        {0,0,0,0,1,0,1,1,1,0,1,1,0,1,1,0,1,0,1,0,0,1,1,0,1,1,1,1,0,0,1,1,1,0,1,0,1},
        {1,0,0,0,1,0,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,1,1,1},
        {1,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,0,1,1,0,0,0},
        {0,1,1,1,1,0,0,0,1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,0,0,0,0,1,1,0,1,0,0,1,1,1,1},
        {0,1,1,1,0,1,0,0,0,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1,0,0,0,1,1,1,0,0,1,1,1,1},
        {0,1,0,0,1,0,0,0,1,0,0,1,1,1,0,0,0,1,1,1,0,1,0,1,1,0,1,0,1,1,1,0,1,1,1,0,0},
        {1,1,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,1,1,1,1,0,0,0,1,0},
        {1,0,0,1,1,1,0,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,1,0,0,0,0,0,0,1,1,0,1},
        {0,0,1,1,1,0,0,1,1,0,1,1,0,1,0,1,1,0,1,1,1,1,1,1,0,1,1,0,1,0,1,1,1,0,0,0,0},
        {1,1,1,0,0,0,0,1,1,0,0,1,0,1,0,0,0,1,1,1,0,0,1,0,1,1,1,1,1,1,1,0,0,1,1,0,1},
        {0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,1,1,1,1,0,1,0,0,0,1,1,0,0,1,0,1,1,1,1,0},
        {0,1,1,1,1,1,0,0,0,1,0,1,1,0,1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0},
        {0,0,1,0,0,1,0,0,1,1,1,0,0,0,0,0,1,1,0,1,0,1,1,1,0,1,0,0,1,0,1,0,0,0,1,1,1},
        {1,0,1,0,1,0,1,1,0,0,0,1,0,0,0,1,1,1,0,1,1,0,1,1,1,0,0,1,1,1,0,0,0,0,0,1,1},
        {0,0,0,1,0,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,1},
        {1,0,0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,0,1,0,0,1,1,1,1,0,1,1},
        {0,1,0,0,0,1,1,1,0,0,1,0,1,0,0,0,1,0,1,1,0,0,1,1,0,0,1,0,0,0,1,1,1,1,1,0,0},
        {0,1,1,1,0,1,0,0,0,0,1,1,1,0,0,1,1,0,0,1,1,1,1,1,0,1,1,0,1,1,0,1,0,1,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,0,0,0,1,1,0,0,1,1,1,1,0,1,1,1,0,0,1,0,0},
        {1,1,0,1,0,0,0,0,0,1,0,1,1,1,1,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,1,1,0},
        {1,0,0,1,1,1,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,1,1,1,1,1,0,0,0,0,1,0,0},
        {1,1,0,0,0,0,1,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1,1,0,0},
        {1,0,1,0,1,0,1,1,0,1,0,0,1,0,0,0,1,1,1,1,0,1,0,0,0,1,0,0,1,1,1,0,1,1,1,1,1},
        {0,0,0,0,0,1,1,1,0,1,0,1,0,0,1,0,1,0,0,0,1,1,0,0,0,1,0,1,0,0,1,0,0,0,1,1,1},
        {0,1,0,1,0,0,0,0,0,0,1,0,1,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0,1,0},
        {0,0,1,0,0,1,1,0,0,1,0,1,0,0,1,1,1,1,0,1,0,0,1,1,1,0,1,1,1,1,0,1,0,1,1,0,1},
        {1,0,0,0,0,0,0,1,0,1,0,1,1,1,0,1,1,0,0,1,0,1,1,0,0,0,0,0,1,1,0,1,1,1,1,0,1},
        {0,1,1,1,0,1,0,1,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,0,0,1,1,1,0}};
    Solution slt;
    // cout << __cplusplus <<endl;
    cout << slt.shortestPathByBFS(grid, 183);
}