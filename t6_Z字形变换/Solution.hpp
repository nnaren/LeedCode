#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
        {
            return s;
        }
        vector<string> rowStr(numRows);
        int row = 0, direction = -1;
        for (int i = 0; i < s.length(); i++) {
            rowStr[row] += s[i];
            direction = (row == numRows - 1  || row ==0) ? -direction  : direction;
            row += direction;
        }
        string ans;
        for(auto curS : rowStr) {
            ans += curS;
        }
        return ans;
    }
};