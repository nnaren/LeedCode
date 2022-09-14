#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        int delNum = n/20;
        sort(arr.begin(), arr.end());
        double sum = 0.0;
        for (int i = delNum; i < n-delNum; i++)
        {
            sum += arr[i];
        }
        
        cout << sum << " " << n-2*delNum << endl;
        return sum/double(n-2*delNum);
    }
};