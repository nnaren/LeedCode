#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> numFrequency;
        // unordered_map<int,int> numFrequency;
        for(auto & n : nums) {
            if (numFrequency.count(n))
            {
                numFrequency[n]++;
            } else {
                numFrequency[n] = 1;
            }
            
        }
        sort(nums.begin(), nums.end(), [&numFrequency] (int x, int y ) { 
                                            if( numFrequency[x] == numFrequency[y])
                                                return x>y;
                                            return numFrequency[x] < numFrequency[y];
                                        }
        ); 
        return nums;
    }

        vector<int> frequencySort2(vector<int>& nums) {
        unordered_set<int> numFrequency;
        // unordered_map<int,int> numFrequency;
        for(auto & n : nums) {
            numFrequency.insert(n);
            
        }
        sort(nums.begin(), nums.end(), [&numFrequency] (int x, int y ) { 
                                            if( numFrequency.count(x) == nnumFrequency.count(y))
                                                return x>y;
                                            return  numFrequency.count(x) < nnumFrequency.count(y);
                                        }
        ); 
        return nums;
    }
};