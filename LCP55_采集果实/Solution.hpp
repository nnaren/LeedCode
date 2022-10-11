#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int getMinimumTime(vector<int>& time, vector<vector<int>>& fruits, int limit) {
        int sum = 0;
        for(int i = 0; i < fruits.size(); i++){
            sum += time[fruits[i][0]] * ((fruits[i][1] + limit-1)/ limit);
        }
        return sum;
    }
};