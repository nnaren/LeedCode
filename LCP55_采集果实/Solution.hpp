#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int getMinimumTime(vector<int>& time, vector<vector<int>>& fruits, int limit) {
        int sum = 0;
        for(auto & fruit : fruits){
            sum += time[fruit[0]] * ((fruit[1] + limit-1)/ limit);
        }
        return sum;
    }
};