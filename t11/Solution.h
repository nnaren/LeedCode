//
// Created by Percy on 2021/10/19.
//

#ifndef T11_SOLUTION_H
#define T11_SOLUTION_H
#include <vector>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0, right =height.size()-1;
        int maxA = 0;
        while(left < right)
        {

            int area = (right-left) * min(height[left], height[right]);
            maxA = max(maxA, area);
            if(height[left] > height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return  maxA;
    }
};
#endif //T11_SOLUTION_H
