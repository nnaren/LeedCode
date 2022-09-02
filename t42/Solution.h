//
// Created by Percy on 2021/11/1.
//

#ifndef T42_SOLUTION_H
#define T42_SOLUTION_H
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans=0;
        stack<int> stk;
        for(int i=0;i<n; i++)
        {
            while(!stk.empty() && height[i] > height[stk.top()]  )
            {
                int base = stk.top();
                stk.pop();
                if(stk.empty())
                    break;
                int left = stk.top();
                int w = i-left-1;
                int h = min(height[left],height[i]) - height[base];
                ans += w*h;
            }
            stk.push(i);
        }
        return ans;
    }
};
#endif //T42_SOLUTION_H
