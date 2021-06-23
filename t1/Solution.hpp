#include<vector>
#include<set>
#include<map>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        set<int> sortedNums(nums.begin(),nums.end());
        auto leftIter = sortedNums.begin(); 
        auto rightIter = sortedNums.rbegin();
        int sz = nums.size();
        vector<int> res;
        int sum;
        while ( true)
        {
            sum = *leftIter + *rightIter;
            if(sum < target) 
            {
                leftIter++;
            }
            else if(sum > target) 
            {
                rightIter++;
            }
            else   break;
        }
        for (int i = 0, j=0; i < sz && j<2; i++)
        {
            if (nums[i] == *leftIter || nums[i] == *rightIter)
            {
                res.push_back(i);
                j++;
            }
        }
        return res;
    }

    vector<int> twoSumUseMap(vector<int>& nums, int target)
    {
        map<int,int> dict;
        int sz = nums.size();
        for(int i=0; i<sz;i++)
        {
            if(dict.count(target-nums[i]))
            {
                return vector<int> {i, dict[target-nums[i]]};
            }
            else
            {
                dict[nums[i]]=i;
            }
            
        }
        return vector<int> {-1, -1};
    }
};
    // {
    //     int sum;
    //     while ( left < right)
    //     {
    //         sum = nums[left] + nums[right];
    //         if(sum < target) left++;
    //         else if(sum > target) right--;
    //         else   break;
    //     }
    //     return vector<int>{left, right};
    // }
