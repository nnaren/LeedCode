#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>> (m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            dfs( board, i, n-1);
            dfs( board, i, 0);
        }
       
        for (int j = 1; j < n; j++)
        {
        
            dfs( board, 0, j);
            dfs( board, m-1, j);
        }
 
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O' && !visited[i][j] )
                {
                    board[i][j] = 'X';
                }
            }
        }
        
    }

    void  dfs( vector<vector<char>>& grid, int i, int j) {
        if(i<0 || i>= m || j<0 || j>=n || grid[i][j] == 'X' || visited[i][j])
        {
            return;
        }
        visited[i][j] = true;
        //向左 
        dfs( grid,  i-1,  j);

        
        dfs( grid,  i+1,  j);
  
        dfs( grid,  i,  j-1);

        dfs( grid,  i,  j+1);
        
    }

    int m, n;
    vector<vector<bool>> visited;

    
};