// 1129. 颜色交替的最短路径
// 在一个有向图中，节点分别标记为 0, 1, ..., n-1。这个图中的每条边不是红色就是蓝色，且存在自环或平行边。

// red_edges 中的每一个 [i, j] 对表示从节点 i 到节点 j 的红色有向边。类似地，blue_edges 中的每一个 [i, j] 对表示从节点 i 到节点 j 的蓝色有向边。

// 返回长度为 n 的数组 answer，其中 answer[X] 是从节点 0 到节点 X 的红色边和蓝色边交替出现的最短路径的长度。如果不存在这样的路径，那么 answer[x] = -1。



#include "Solution.hpp"

int main()
{

    int n = 3;
    vector<vector<int>>red_edge = {{0,1},{0,2},{1,0}};
    vector<vector<int>>blue_edge = {{0,1},{0,2},{1,0}};
    Solution slt;
    // cout << __cplusplus <<endl;
    for(auto step : slt.shortestAlternatingPaths(n, red_edge, blue_edge))
        cout << step << endl;
}