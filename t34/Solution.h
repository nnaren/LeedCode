//
// Created by Percy on 2021/10/21.
//

#ifndef T34_SOLUTION_H
#define T34_SOLUTION_H
#include <vector>
using namespace  std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
            return vector<int>{-1,-1};
        int firstPosition = findFirstPosition(nums, target);
        if(firstPosition == -1)
            return vector<int>{-1, -1};
        int lastPosition = findLastPosition(nums, target);
        return vector<int> {firstPosition, lastPosition};
    }
    int findFirstPosition(vector<int>& nums, int target)
    {
        int L = 0 ;
        int R =  nums.size()-1;
        while(L<R)
        {
            int M = (L+R)>>1;
            if( target > nums[M])
            {
                L = M+1;
            } else if(target == nums[M])  // 右边不是第一个位置。
            {
                R = M;
            } else {
                R = M-1;  //Mid 和 Mid 右边
            }

        }
        if(target == nums[L] )
            return L;
         else
            return -1;
    }
    int findLastPosition(vector<int>& nums, int target)
    {
        int L = 0 ;
        int R =  nums.size()-1;
        while(L<R)
        {
            int M = (L+R+1)>>1;
            if( target > nums[M])
            {
                L = M+1;
            } else if(target == nums[M])  // 左边不是最后一个位置。
            {
                L = M;
            } else {
                R = M-1;  //Mid 和 Mid 左边
            }

        }
        if(target == nums[L])
            return L;
        else
            return -1;
    }
//    vector<int> searchRange(vector<int>& nums, int target) {
//        int low = 0;
//        int high = nums.size()-1;
//        int mid;
//        int L = -1;
//        int R = -1;
//        while(low <= high)
//        {
//            mid = (low+high)/2;
//            if (target == nums[mid])
//            {
//                L = R= mid;
//                break;
//            }
//            else if(target > nums[mid] )
//            {
//                low = mid+1;
//            }  else {
//                high = mid-1;
//            }
//        }
//        if(L == -1)
//            return vector<int>(2,-1);
//        while(L>0 )
//        {
//            if(nums[L-1]!= target)
//                break;
//            L--;
//        }
//        while(R < nums.size()-1 )
//        {
//            if(nums[R+1] != target)
//                break;
//            R++;
//        }
//        return vector<int>{L,R};
//    }
};
#endif //T34_SOLUTION_H
