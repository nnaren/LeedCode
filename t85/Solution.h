//
// Created by Percy on 2021/10/28.
//

#ifndef T85_SOLUTION_H
#define T85_SOLUTION_H
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> heights(matrix.size(),vector<int >(matrix[0].size(),0));

        for(int j=0; j<matrix[0].size();j++)
        {
            if(matrix[0][j] == '1')
            {
                heights[0][j] = 1;
            }

        }
        int res = largestRectangleArea(heights[0]);

        for(int i=1; i<matrix.size();i++)
        {
            for(int j=0; j<matrix[0].size();j++)
            {
                if(matrix[i][j] == '1')
                    heights[i][j] = heights[i-1][j]+1;
            }
            res = max(res, largestRectangleArea(heights[i]));
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<int> mono;
        int n = heights.size();
        vector<int> left(n), right(n);

        for(int i =0; i<n;i++)
        {
            while(!mono.empty() && heights[mono.top()] >= heights[i] )
            {
                mono.pop();
            }
            left[i] = (mono.empty() ? -1 : mono.top());
            mono.push(i);
        }
        mono = stack<int> ();
        for(int i =n-1; i>=0;i--)
        {
            while(!mono.empty() && heights[mono.top()] >= heights[i] )
            {
                mono.pop();
            }
            right[i] = (mono.empty() ? n : mono.top());
            mono.push(i);
        }
        int res = 0;
        for(int i =0;i<n;i++)
        {

            res = max(heights[i] *(right[i]- left[i]-1) , res);
        }
        return res;
    }
};
#endif //T85_SOLUTION_H
