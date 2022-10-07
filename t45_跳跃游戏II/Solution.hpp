#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // 贪心算法， 因为选择的每一步都是在远的 [2,3,1,1,4]
    int jump(vector<int>& nums) {
        int n = nums.size();
        int site = 0;
        int step = 0;
        while(site < n-1){
            int far = 0;
            int choise ;
            for(int i = 1; i<= nums[site]  ;i++)
            {
                if(site+i == n-1) {
                    choise = i;
                    break;
                }
                if(far<site+i+nums[site+i]) {
                    far = site + i + nums[site+i];
                    choise = i;
                }
                
            }
            cout << choise << endl;
            site += choise;
            step++;
        }
        return step;
    }
};