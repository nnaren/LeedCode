//
// Created by Percy on 2021/10/21.
//

#ifndef T48_SOLUTION_H
#define T48_SOLUTION_H
#include <vector>

using namespace std;
void show(vector<vector<int>>& matrix)
{
    for (auto v : matrix)
    {
        for(auto vv: v)
        {
            cout << vv << " " ;
        }
        cout << endl;
    }
}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i<n/2; i++)
        {
            for(int j=i; j<n-1-i;j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
    }
};

#endif //T48_SOLUTION_H
