#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution
{
private:
    vector<vector<string>> chess;

public:
    vector<vector<string>>  solveNQueens(int n)
    {
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
    
        return chess;
    }
    bool isValid(int row, int col, vector<string>& chessboard)
    {
        int n = chessboard[0].size();
        for (int i = 1; i <= row; i++)
        {
            if (chessboard[row-i][col] == 'Q')
            {
                return false;
            }
            if (col+i<n && chessboard[row-i][col+i] == 'Q')
            {
                return false;
            }
            if (col>=i && chessboard[row-i][col-i] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
    void backtracking(int n, int row , vector<string>& chessboard)
    {
        if (row == n)
        {
            chess.push_back(chessboard);
            return;
        }
        
        for (int j = 0; j < n; j++)
        {
            if(isValid(row, j, chessboard))
            {
                chessboard[row][j] = 'Q';
                backtracking(n, row+1, chessboard);
                chessboard[row][j] = '.';
            }
        }
        
    }
};

