//
// Created by Percy on 2021/10/27.
//

#ifndef T240_SOLUTION_H
#define T240_SOLUTION_H
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();

        int i = 0;
        int j = n-1;
        while(i < m && j >= 0)
        {
            if(matrix[i][j] == target){
                return true;
            } else if (matrix[i][j]> target)
            {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }

};
#endif //T240_SOLUTION_H
