//
// Created by Percy on 2021/10/23.
//

#ifndef T79_SOLUTION_H
#define T79_SOLUTION_H
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for(int i = 0;i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (check(i,j,visited, board, word,0))
                {
                    return true;
                }
            }
        }
        return false;
    }
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool check(int i, int j,vector<vector<bool>> visited, vector<vector<char>>& board, string word, int step)
    {
        if(board[i][j] != word[step])
        {
            cout << "("<< i <<j <<")"<< "No, Need: "<<word[step];
            return false;
        } else if(step == word.size()-1){
            return true;
        }

        cout << "Step: " << step <<" Add : ("<< i <<j <<")"<< board[i][j]<< " ,";
        visited[i][j] = true;
        bool result = false;
        for (auto& dire: directions) {
            int newi  = i + dire.first;
            int newj  = j + dire.second;

            if(newi>=0 && newj >=0 &&
                newi<board.size() && newj<board[0].size() &&
                !visited[newi][newj]) {
                if(check(newi, newj, visited, board, word, step+1))
                {
                    result = true;
                    break;
                }
            }

        }
        cout << "Del : ("<< i <<j <<")"<< board[i][j]<<endl;
        visited[i][j] = false;
        return result;
    }
};

#endif //T79_SOLUTION_H
