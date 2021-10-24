#include <iostream>
#include "Solution.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
//    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
//                                  {'S', 'F', 'C', 'S'},
//                                  {'A', 'D', 'E', 'E'}};
    vector<vector<char>> board =
            {{'A','A','A','A','A','A'},
             {'A','A','A','A','A','A'},
             {'A','A','A','A','A','A'},
             {'A','A','A','A','A','A'},
             {'A','A','A','A','A','A'},
             {'A','A','A','A','A','A'}};
    string word = "AAAAAAAAAAAAAAB";

    Solution sol;
    if(sol.exist(board,word))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
