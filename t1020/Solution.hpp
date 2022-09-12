#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>> (m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            dfs( grid, i, n-1);
            dfs( grid, i, 0);
        }
       
        for (int j = 1; j < n; j++)
        {
        
            dfs( grid, 0, j);
            dfs( grid, m-1, j);
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && !visited[i][j] )
                {
                    ans++;
                }
            }
        }
        return ans;
    }

    void  dfs( vector<vector<int>>& grid, int i, int j) {
        if(i<0 || i>= m || j<0 || j>=n || grid[i][j] == 0 || visited[i][j])
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
    int numEnclaves2(vector<vector<int>>& grid) {
        int mm = grid.size(); int nn = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(mm, vector<bool>(nn, false));
        queue<pair<int, int>> que;
        for (int i = 0; i < mm; i++)
        {
            if (grid[i][0] == 1) {
                visited[i][0] = true;
                que.push({i,0});
            }
            if (grid[i][nn - 1] == 1) {
                visited[i][nn - 1] = true;
                que.push({i,nn-1});
            }
        }
       
        for (int j = 1; j < nn; j++)
        {        
            if (grid[0][j] == 1) {
                visited[0][j] = true;
                que.push({ 0, j});
            }
            if (grid[mm-1][j] == 1) {
                visited[mm - 1][j] = true;
                que.push({ mm-1, j});
            }
        }
        while (!que.empty()) {
            auto [i, j] = que.front(); 
            que.pop();
            int  nextI = i + 1, nextJ = j;
            if (nextI >= 0 && nextI < mm && nextJ >= 0 && nextJ < nn
                && grid[nextI][nextJ] == 1
                && !visited[nextI][nextJ]) {
                visited[nextI][nextJ] = true;
                que.push({nextI, nextJ});
            }

            nextI = i - 1, nextJ = j;
            if (nextI >= 0 && nextI < mm && nextJ >= 0 && nextJ < nn
                && grid[nextI][nextJ] == 1
                && !visited[nextI][nextJ]) {
                visited[nextI][nextJ] = true;
                que.push({nextI, nextJ});
            }

            nextI = i , nextJ = j-1;
            if (nextI >= 0 && nextI < mm && nextJ >= 0 && nextJ < nn 
                && grid[nextI][nextJ] == 1
                && !visited[nextI][nextJ]) {
                visited[nextI][nextJ] = true;
                que.push({nextI, nextJ});
            }

            nextI = i , nextJ = j+1;
            if (nextI >= 0 && nextI < mm && nextJ >= 0 && nextJ < nn 
                && grid[nextI][nextJ] == 1
                && !visited[nextI][nextJ]) {
                visited[nextI][nextJ] = true;
                que.push({nextI, nextJ});
            }
           
        }
        int ans = 0;
        for(int i = 0; i < mm; i++) {
            for(int j = 0; j < nn; j++) {
                if(grid[i][j] == 1 && !visited[i][j] )
                {
                    ans++;
                }
            }
        }
        return ans;

    }

    
    int m, n;
    vector<vector<bool>> visited;

    
};