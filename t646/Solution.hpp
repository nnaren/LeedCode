#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n-1];
    }

    // 贪心算法
    int findLongestChain2(vector<vector<int>>& pairs) { 
        int curr = INT_MIN;
        int res = 0;
        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b) {
                return a[1] < b[1];
            }
        );
        for (auto& p: pairs) {
            if (curr < p[0]) {
                curr = p[1];
                res++;
            }
        }
    }

    // 最长递增子序列   贪心+二分查找 arr[i]表示长度为i+1d 数对链的末尾可取的最小值
    int findLongestChain3(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> arr;
        for (auto p : pairs) {
            int x = p[0], y = p[1];
            if (arr.size() == 0 || x > arr.back()) {
                arr.emplace_back(y);
            } else {
                int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
                arr[idx] = min(arr[idx], y);
            }
        }
        return arr.size();
    }



};