#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> coins  {25, 10, 5, 1};
public:
    int waysToChange(int n) {
        int  mod = 1000000007 ;
        vector<int> ways(n+1);
        ways[0] = 1;
        for (int j = 0; j<4; j++) {
            for (int i = coins[j]; i<n+1; i++) {

                    ways[i] = (ways[i] + ways[i-coins[j]]) % mod;
                
                
            }
        
        }
       
        return ways[n];
    }
};