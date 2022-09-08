#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> map ;
        int n = s.length();
        vector<string> ans;
        for (int i = 0; i < n-10; i++)
        {
            string temp = s.substr(i, 10);
            map[temp]++;
            if(map[temp] ==2) {
                ans.emplace_back(temp);
                cout << temp<<endl;
            }
        }
        return ans;
    }
};