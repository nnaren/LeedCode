#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int  m = mat.size();
        int  n = mat[0].size();
        vector<int> hasRows(m, 0);
        vector<int> hasCols(n, 0);
        int ans = 0;
        for(int i = 0; i< m;i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    hasRows[i]++;
                    hasCols[j]++;
                }
            }
        }
        for(int i = 0; i< m;i++){
            for(int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && hasRows[i] ==1 && hasCols[j] == 1) {
                    ans++;
                }
            }
        }
            return ans;
    }
};