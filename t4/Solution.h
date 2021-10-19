//
// Created by Percy on 2021/10/19.
//

#ifndef T4_SOLUTION_H
#define T4_SOLUTION_H
#include <vector>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1= nums1.size();
        int len2 =nums2.size();
        int mid = (len1+len2)/2;
        int index = 0;
        double ans1 = 0, ans2=0;
        int i = 0, j=0;
        for(; i < len1 && j < len2 ; )
        {
            if(nums1[i]<nums2[j])
            {
                ans2 = nums1[i];
                i++;
            }else{
                ans2 = nums2[j];
                j++;
            }
            if(index ==  mid)
            {
                if((len1+len2)%2 == 0)
                {
                   return (ans2+ ans1)/2;
                }
                else {
                    return ans2;
                }
            }
            index++;
            ans1 = ans2;
        }
        while(i < len1)
        {
            ans2 = nums1[i];
            i++;
            if(index ==  mid)
            {
                if((len1+len2)%2 == 0)
                {
                    return (ans2+ ans1)/2;
                }
                else {
                    return ans2;
                }
            }
            index++;
            ans1 = ans2;
        }
        while(j < len2)
        {
            ans2 = nums2[j];
            j++;
            if(index ==  mid)
            {
                if((len1+len2)%2 == 0)
                {
                    return (ans2+ ans1)/2;
                }
                else {
                    return ans2;
                }
            }
            index++;
            ans1 = ans2;
        }

    }
};

#endif //T4_SOLUTION_H
