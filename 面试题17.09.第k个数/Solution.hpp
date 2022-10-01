#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int getKthMagicNumber(int k) {
        int n3=0,n5=0,n7=0;
        vector<int> ans(k, 1);
        for(int i=1; i<k;i++) {
            ans[i] = min(ans[n3]*3, min(ans[n5]*5, ans[n7]*7));
            if(ans[i] == ans[n3]*3) {
                n3++;
            }
            if(ans[i] == ans[n5]*5) {
                n5++;
            }
            if(ans[i] == ans[n7]*7) {
                n7++;
            }
            
        }
        return ans[k-1];
    }
};