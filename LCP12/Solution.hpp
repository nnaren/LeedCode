#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minTime(vector<int>& time, int m) {
        int low = 0 ,mid =0;
        int high = 0;
        for (int i = 0; i < time.size(); i++)
        {
            high += time[i];
        }
        
        while (low <= high)
        {
            mid = (low + high) / 2;
            if(check(time, mid, m)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    bool check(vector<int> time, int allowTime, int dueDay) {
        int actualDays = 1;
        int maxTime = 0;
        int totalTime = 0;
        for (int i = 0; i < time.size(); i++)
        {
            int curTime = min(time[i], maxTime); // 选当前还是选
            if(curTime  + totalTime <= allowTime) {
                
                totalTime += curTime;
                maxTime = max(time[i], maxTime);
            } else {
                actualDays++;
                totalTime = 0;
                maxTime = time[i];
            }
        }
        return actualDays <= dueDay;
        
    }
};