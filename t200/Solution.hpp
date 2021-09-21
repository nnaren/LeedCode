#include<vector>
#include<iostream>
using namespace std;
class Solution
{
private:
    int m;
    int n;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1') {

                
                    backtracking(grid, i, j);
                    res++;
                }
            }
        }

        return res;
    }


    void backtracking(vector<vector<char>>& grid, int i, int j)
    {
        if( i < 0 || i >= m ||
            j < 0 || j >= n ||
            grid[i][j] == '2' ||
            grid[i][j] == '0')
            return;
        grid[i][j] = '2';
        backtracking(grid,i-1,j);
        backtracking(grid,i+1,j);
        backtracking(grid,i,j-1);
        backtracking(grid,i,j+1);
    }
};

