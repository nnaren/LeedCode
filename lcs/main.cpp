#include<string>
#include<iostream>
#include "lcs.h"
using namespace std;

int main()
{
    string str1("ab1234cd");
    string str2("a123612345c");
    string result = lcsUseMap(str1, str2);
    cout << result;
    return 0;
}