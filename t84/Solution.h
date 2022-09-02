//
// Created by Percy on 2021/10/28.
//

#ifndef T84_SOLUTION_H
#define T84_SOLUTION_H
#include <stack>
using namespace  std;
class Solution {
public:
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
#endif //T84_SOLUTION_H
