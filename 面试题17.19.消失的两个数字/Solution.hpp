#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size();
        int allSum = 0;
        int othersSum = 0;
        for(auto i: nums) {
            othersSum += i;
            
        }
        for(int i =1; i<=n+2;i++) {
            allSum += i;
        }
        int twoSum = allSum - othersSum;
        int mid = twoSum/2;
        int leftOthersSum = 0;
        cout << leftOthersSum << endl;
        for(auto i: nums) {
            if(i <= mid)
                leftOthersSum += i;  
        }
        int leftAllSum = 0;
        for(int i =1; i<=mid;i++) {
            leftAllSum += i;
        }
        int littleOne = leftAllSum - leftOthersSum;
        int bigOne = twoSum - littleOne;
        return {littleOne, bigOne};
    }
};