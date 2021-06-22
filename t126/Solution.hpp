
#include<string>
#include<vector>
#include<deque>
#include<iostream>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end() );
        
        vector<vector<string>> res;
        deque<vector<string>> path;
        path.push_back({beginWord});
        while (!path.empty())
        {
            // 每一层添加使用完的单词
            // 每次需要清0，所以放在该作用域从新定义，自动清0；
            // 使用set原因是最后找到尾单词，可能有多个路径，结果都是尾单词，导致重复。
            // 与dict组成，（used，dict）小组，删掉使用的节点。
            unordered_set<string> used;
            for (int i = path.size(); i>0; i--) // 路径层数：每一层有一组，单词个数相等，每组单词个数依次增加1；
            {
                auto sub = path.front();    // 子路径： 每层含有多个子路径，
                path.pop_front();
                auto tail = sub.back();
                if(tail == endWord)
                {
                    res.push_back(sub);
                    continue;
                }
                for (int j = 0; j < tail.size(); j++)   // 单词含有字母个数，依次进行替换，找相邻的单词
                {
                    char temp = tail[j];
                    for (char c = 'a'; c < 'z'; c++)
                    {
                        if (c == temp)  continue;
                        tail[j] = c;
                        if (!dict.count(tail))  continue;
                        used.emplace(tail);
                        sub.push_back(tail);   // dfs  回溯开始：添加新的单词
                        path.push_back(sub);
                        sub.pop_back();         // dfs 回溯恢复：删掉新的单词
                    }
                    tail[j] = temp;
                }
                
                
            }
            if(res.size())  return res;
            for(auto word:used)    // auto& 和 auto
                dict.erase(word);
        }
        return {};
    }
};