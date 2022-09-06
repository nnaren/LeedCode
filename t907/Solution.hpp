#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       int mod = 1000000007 ;
       int n = arr.size();
    
       stack<int> stackLeft;
       vector<int> left(n);  // 左边都大于或者等于
       for(int i = 0; i < n; i++)
       {
            while(!stackLeft.empty() && arr[i] <= arr[stackLeft.top()]){
                stackLeft.pop();
            }
            left[i] = stackLeft.empty() ? -1 : stackLeft.top();
            stackLeft.push(i);
       }

       stack<int> stackRight;
       vector<int> right(n);  // 右边都大于
       for(int i = n-1; i >=0 ; i--)
       {
            while(!stackRight.empty() && arr[i] < arr[stackRight.top()]){
                stackRight.pop();
            }
            right[i] = stackRight.empty() ? n : stackRight.top();
            stackRight.push(i);
       }
        long ans = 0;

        for(int i= 0; i < n; i++) {
            ans += long((i-left[i]) * (right[i] - i)) % mod * arr[i] % mod;
            ans %= mod;
        }
        return ans;
    }


    // 问题：相同的最小值都未计算。
    int sumSubarrayMins2(vector<int>& arr) {
        int mod = 1000000007 ;
        unordered_map<int, vector<int> > i_left_right;
        for(int i = 0; i < arr.size(); i++) {
            i_left_right[i].emplace_back(-1);
            for(int j = i-1; j>=0; j--) {
                if (arr[i]>=arr[j]) {
                    i_left_right[i][0] = j;
                    break;
                }
            }
            
            
            
            i_left_right[i].emplace_back(arr.size());
            
            for(int j = i+1; j<arr.size(); j++) {
                if (arr[i] >= arr[j]) {
                    i_left_right[i][1] = j;
                    break;
                }
            }
            
        }
        long ans = 0;
        for (auto &&[num, left_right] : i_left_right)
        {   
            ans += arr[num] * (num-left_right[1]) *(left_right[0]-num) % mod;
        }
        return ans;
    }
};