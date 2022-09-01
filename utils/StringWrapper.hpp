#include <string> 
#include <vector>
using namespace std;
inline vector<string> split(string str, string separator) {
    vector<string> result;
    size_t cutAt = str.find_first_of(separator);
    while (cutAt != string::npos) {
        if (cutAt > 0 && cutAt < str.length()) {
            result.append(str.substr(0, cutAt));
        }
        if (cutAt + 1 < str.length()) {
            str = str.substr(cutAt + 1);
            cutAt = str.find_first_of(separator);
        } else {
            return result;
        }
    }
    if(str.length() > 0) {
        result.append(str);
    }
    return result;
}

template <class Type>
Type string2Num(const string& str) {
    std::istringStream iss(str);
    Type num;
    iss >> num;
    return num;
}