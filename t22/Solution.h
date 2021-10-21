//
// Created by Percy on 2021/10/20.
//

#ifndef UNTITLED_SOLUTION_H
#define UNTITLED_SOLUTION_H
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {

        unordered_map<char, int> pt_r_num = {{'(', n},{ ')',n}};
        vector<char> choice = {'(', ')'};
        string path;
        trackback(pt_r_num, path, choice);
    }

    void trackback(unordered_map<char, int> pt_r_num, string path ,vector<char> choice)
    {
        for(auto c: choice)
        {
            if(pt_r_num[')'] == 0)
            {
                result.push_back(path);
                cout << path << endl;
                return;
            }
            if(c == '(' && pt_r_num['(']== 0)
            {
                continue;
            } else if(c == ')' && pt_r_num['('] == pt_r_num[')'])
            {
                continue;
            }


            path += c;
            pt_r_num[c]--;
            trackback(pt_r_num, path, choice);
            path = path.substr(0, path.size()-1);
            pt_r_num[c]++;
        }

    }
};
#endif //UNTITLED_SOLUTION_H
