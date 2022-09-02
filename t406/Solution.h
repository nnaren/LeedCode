//
// Created by Percy on 2021/10/28.
//

#ifndef T406_SOLUTION_H
#define T406_SOLUTION_H
#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](vector<int>& u, vector<int>& v) {
            return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]); // > 意义：相同身高，排后面的先选，排前面的占empty()
        });
        vector<vector<int>> res(n);
        for(const auto& person: people)
        {
            int p = person[1];
            for(int i=0;i<n ; i++)
            {
                if(res[i].empty())  //说明留给比他高的人
                {
                    if (p == 0) {
                        res[i] = person;
                        break;
                    }
                    p--;
                }
            }
        }
        return res;
    }
};
#endif //T406_SOLUTION_H
