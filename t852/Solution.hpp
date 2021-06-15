#include <vector>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int high = arr.size()-1;
        int low = 0;
        int mid = 0;
        while(low<=high)
        {
            mid = (high+low)/2;
            if(mid==0)
                return 1;
            if(arr[mid-1]<arr[mid])
            {
                if(arr[mid]>arr[mid+1])
                    return mid;
                else
                    low = mid+1;
            }
            else
            {
                high = mid-1;
            }
                
            
        }
        return mid;
    }
};