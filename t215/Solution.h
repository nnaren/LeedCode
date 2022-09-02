//
// Created by Percy on 2021/10/27.
//

#ifndef T215_SOLUTION_H
#define T215_SOLUTION_H
#include <vector>

using namespace std;
class Solution {
public:
    int partition(vector<int>& nums, int l, int r)
    {
        int pivot = l + rand()% (r-l+1)  ;
        int x = nums[pivot];
        swap(nums[pivot], nums[r]);
        int pivotIndex = l;
        for(int i=l;i<r;i++)
        {
            if(nums[i]<=x)
                swap(nums[pivotIndex++], nums[i]);
        }
        swap(nums[pivotIndex], nums[r]);
        return pivotIndex;
    }
    int quicksort(vector<int>& nums, int l, int r, int k)
    {
        int p = partition(nums, l, r);
        if(p==k)
        {
            return nums[k];
        } else if(p<k)
        {
            return quicksort(nums, p+1,r,k);
        } else {
            return quicksort(nums, l, p-1,k);
        }

    }
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quicksort(nums, 0, nums.size()-1, nums.size()-k);
    }
};
#endif //T215_SOLUTION_H
