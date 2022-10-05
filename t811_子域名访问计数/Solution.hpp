#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> count;
        vector<string> ans;
        for(auto domain : cpdomains) {
            int num;
            int n = domain.size();
            for(int i =0; i<n;i++) {
                if(domain[i] == ' '){
                    num = atoi(domain.substr(0, i).c_str());
                    count[domain.substr(i+1)] += num;
                }
                if(domain[i] == '.') {
                    string cDomain = domain.substr(i+1);
                    
                    count[cDomain] += num;
                    
                    
                }
            }
        }
        for(auto [k, v] : count) {
            string cpdomain = to_string(v) + " " + k;
            // cout << cpdomain << endl;
            ans.push_back(cpdomain);
        }
        return ans;
    }
};