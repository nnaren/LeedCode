#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reformatNumber(string number) {
        string phoneNumber;
        for (auto & ch: number) {
            if(isdigit(ch)) {
                phoneNumber.push_back(ch);
            }
        }
        int n = phoneNumber.size();
        string ans;
        int point = 0;
        while(n) {
            if(n>4) {
                ans += phoneNumber.substr(point,3) + "-";
                point +=3;
                n -= 3;
            } else {
                if(n==4){
                    ans+= phoneNumber.substr(point,2) + "-" + phoneNumber.substr(point+2,2);
                } else {
                    ans += phoneNumber.substr(point,n);
                }
                break;
            }
        }
        return ans;
    }
};