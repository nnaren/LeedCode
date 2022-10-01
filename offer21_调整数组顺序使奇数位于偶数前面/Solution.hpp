#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // 前后指针
    vector<int> exchange(vector<int>& nums) {
        int front=0,back = 0;
        while (front<nums.size()) {
            
            if(nums[front] % 2==0) {
                front++;

            } else {
                if(front > back) {
                    swap(nums[front], nums[back]);
                    
                }
                front++;
                back++;
            }
        }
        return nums;
    }
    // 左右指针
    vector<int> exchange2(vector<int>& nums) { 
       int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (left < right and nums[left] % 2 == 1) {
                left++;
            }
            while (left < right and nums[right] % 2 == 0) {
                right--;
            }
            if (left < right) {
                swap(nums[left++], nums[right--]);
            }

        } 
    }
};