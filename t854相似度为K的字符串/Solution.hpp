#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <functional>
#include <climits>
using namespace std;

class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int n = s1.length();
        queue<pair<string, int>> que;
        unordered_set<string> visited;
        que.emplace(s1, 0);
        int step = 0;
        for(; step < n; step++) {
            int curNum = que.size();
            for(int i = 0; i < curNum; i++) {
                auto [cur, pos] = que.front();
                que.pop();
                if(cur == s2) {
                    return step;
                }
                // 前进
                while (pos< n && cur[pos] == s2[pos]) {
                    pos++;
                }
                for(int j = pos+1; j<n; j++) {
                    if(cur[j] != s2[j] && cur[j] == s2[pos]) {
                        swap(cur[j], cur[pos]);
                        if( !visited.count(cur)) {
                            visited.emplace(cur);
                            que.emplace(cur, pos+1);
                        }
                        swap(cur[j], cur[pos]);
                    }
                }
            } 
        }
        return step;
    }

    int kSimilarityDFS(string s1, string s2) {
        int n = s1.length();
        int ans = INT_MAX;
        function<void(int, int)> dfs = [&](int pos, int step) {
            if(s1 == s2) {
                ans = min(step,ans);
                return;
            }
                
            while(pos < n && s1[pos] == s2[pos]) pos++;
            for(int j = pos+1; j<n; j++) {
                if(s1[j] != s2[j] && s1[j] == s2[pos]) {
                  
                    swap(s1[j], s1[pos]);
                    dfs(pos+1,step+1);
                   
                    swap(s1[j], s1[pos]);
                }
            }
            
        };
        dfs(0,0);
        return ans;
    }
};