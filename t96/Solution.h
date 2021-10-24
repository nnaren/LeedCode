//
// Created by Percy on 2021/10/24.
//

#ifndef T96_SOLUTION_H
#define T96_SOLUTION_H
#include <vector>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n+1);
        res[0]=1;
        res[1]=1;

        for(int i=2; i <= n; i++)
        {
            for(int j=0; j< i;j++)
            {
                res[i] += (res[j] * res[i-1-j]);
            }

        }
        return res[n];
    }

};
#endif //T96_SOLUTION_H
