#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;;
        int n=prices.size();
        int c=1;
        for (int i =0 ; i<n; i++) {
            ans += c;
            if(i == n-1){
                break;
            }
            if(prices[i] == prices[i+1]+1) {
                c++;
            } else {
                c = 1;
            }
        }
        return ans;
    }
};