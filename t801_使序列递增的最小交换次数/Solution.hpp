#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int exchange = 1;
        int noExchange = 0;
        for(int i=1 ; i< nums1.size(); i++) {
            int e_temp = exchange;
            int n_temp = noExchange;
            if(nums1[i]> nums1[i-1] && nums2[i] > nums2[i-1]) {
                // noExchange ;
                cout << "case1" << endl;
                exchange = e_temp +1;
            } else {
                noExchange = exchange = nums1.size();
            }
            if(nums1[i]> nums2[i-1] && nums2[i] > nums1[i-1]) {
                cout << "case2" << endl;
                noExchange =  min(noExchange, e_temp);
                exchange = min(n_temp+1, exchange);
            }
            cout << " exchange " << exchange << ", noExchange" << noExchange << endl;
        }
        return min(exchange, noExchange);
    }
};