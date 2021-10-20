//
// Created by Percy on 2021/10/20.
//

#ifndef T17_SOLUTION_H
#define T17_SOLUTION_H
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> result;
    unordered_map<char, string> digit2Char = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6',"mno"},
    {'7',"pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    
    vector<string> letterCombinations(string digits) {

        string path;
        int level = 0;
        dfs( path, level, digits);
        return  result;
    }
    void dfs(string path,int  level, string digits)
    {
        for(auto c: digit2Char[digits[level]])
        {
            path+=c;
            level++;
            if(level == digits.size())
            {
                result.push_back(path);
                cout << path  <<endl;
            }
            else {
                dfs(path, level, digits);
            }
            path=path.substr(0,path.size()-1);
            level--;
        }
    }
};
#endif //T17_SOLUTION_H
