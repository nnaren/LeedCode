#include <iostream>
using namespace std;
template<typename T>
inline void show(T container)  {
    for(auto && a : container) {
        cout << a << ", ";
    }
     cout << endl;
}