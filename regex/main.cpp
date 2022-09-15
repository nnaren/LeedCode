#include <iostream>
#include "Solution.hpp"
#include "match.h"
using namespace std;
int main() {
    char * a = "abc";
    char * b = "abb*c";
    if(match(a, b)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}
