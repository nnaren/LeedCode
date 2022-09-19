#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int t) {

        if(i>=0 && i<n && j>=0 && j<n && grid[i][j] == 1) {
            grid[i][j] = t;
            islandNameToArea[t]++;
            dfs(grid, i-1, j, t);
            dfs(grid, i+1, j, t);
            dfs(grid, i, j-1, t);
            dfs(grid, i, j+1, t);
        }
        
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        int t = 2;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                dfs(grid, i, j, t);
                if(grid[i][j] != 0) {
                    ans = max(ans, islandNameToArea[t]);
                    t++;
                }   
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0){
                    unordered_set<int> connected;
                    int z = 1;
                    if(i+1<n && grid[i+1][j]>1 && connected.count(grid[i+1][j]) == 0) {
                        connected.emplace(grid[i+1][j]);
                        z += islandNameToArea[grid[i+1][j]];
                    }
                    if(i-1>=0 && grid[i-1][j]>1 && connected.count(grid[i-1][j]) == 0) {
                        connected.emplace(grid[i-1][j]);
                        z += islandNameToArea[grid[i-1][j]];
                    }
                    if(j+1<n && grid[i][j+1]>1 && connected.count(grid[i][j+1]) == 0) {
                        connected.emplace(grid[i][j+1]);
                        z += islandNameToArea[grid[i][j+1]];
                    }
                    if(j-1>=0 && grid[i][j-1]>1 && connected.count(grid[i][j-1]) == 0) {
                        connected.emplace(grid[i][j-1]);
                        z += islandNameToArea[grid[i][j-1]];
                    }
                    ans = max(ans, z);
                }
            }
        }
        return ans;
        
    }
    unordered_map<int, int> islandNameToArea;
    int n;
    int ans = 0;
};