
// 题目：t52-  n 皇后问题 
// 归类： 回溯
// 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
#include"Solution.hpp"
#include<iostream>
int main()
{
    Solution sol;
    int n = 9;
    int num = sol.totalNQueens(n);

    std::cout << "共计： " << num << std::endl;

}