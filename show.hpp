#include <iostream>
using namespace std;
template<typename T>
inline void show(T container)  {
    for(auto && a : container) {
        cout << a << ", ";
    }
     cout << endl;
}

template<typename T>
inline void show2D(T board) {
    int m = board.size();
    int n = board[0].size();
    cout << "[";
    for(int i = 0; i < m;i++){
        
        for(int j = 0; j < n; j++) {
            if(j == 0) {
                cout << "[" ;
            }
            cout << "\""<<board[i][j] << "\"" ;
            if(j<n-1) {
               cout <<",";
            }
            if(j == n-1) {
                cout << "]";
                if(i < m-1){
                    cout << ",";
                }
            }
        }
    }
    cout << "]";
}