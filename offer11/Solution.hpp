#include<vector>
#include<iostream>
using namespace std;
class Solution
{
private:
    /* data */
public:
    static int search(vector<int >& nums, int target)
    {
        int size = nums.size();
        if (size == 0)
        {
            return -1;
        }
        int low = 0, high = size-1 ,mid;
        while (low < high)
        {
           
            mid = (high+low)/2;
            if(nums[mid] > nums[high])
            {
                low=mid+1;
                
            } else if(nums[mid] < nums[high] )
            {
                high = mid;
            } else
            {
                high--;
            }
            
        }
         
        return low;
    }
        static int search2(vector<int >& nums, int target)
    {
        int size = nums.size();
        if (size == 0)
        {
            return -1;
        }
        int low = 0, high = size-1 ,medium;
        while (low < high)
        {
            if (nums[low] == nums[high])
            {
                low = low+1;
                continue;
            }
            
            medium = (high+low)/2;              
            // 只要中间值不等于第一个和最后一个，说明起始值可以不在两边，一定 第一个 >= 最后一个。所以只要中间值和最后值比较。
            // 大于最后值，说明最小值在中间靠后，不包含最中间值 所以medium+1
            // 小于最后值，说明最小值在中间靠前，包含中间值所以medium
            // 等于最值，缓慢从后缩小。
            if(nums[medium] >= nums[low] && nums[medium] > nums[high])  // 如果 中间值很大（大于第一个和最后一个），说明最小的在中间和最后一个，隐含信息 
            {
                low=medium+1;
                
            } else if(nums[medium] < nums[low] && nums[medium] <= nums[high]){
                
                high = medium;
            } else
            {
                return low;
            }
            
        }
         
        return low;
    }
};