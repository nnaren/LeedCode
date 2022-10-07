#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int reverse = 0;
        int temp = x;
        while(temp){
            reverse = reverse*10 + temp % 10;
            temp /= 10;
        }
        // cout << reverse << endl;
        return reverse == x;
    }
};