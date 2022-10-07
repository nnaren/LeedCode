#include <iostream>
#include "../show.hpp"
#include "Solution.hpp"

int main() {
    vector<vector<char>> board{{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    show2D(board);
    Solution sol;
    return 0;
}
