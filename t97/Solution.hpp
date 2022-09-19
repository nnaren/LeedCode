#include<string>
#include <vector>
#include<iostream>
using  namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if(n1+n2 != n3) return false;
        auto check = vector<int>(n2+1, false);
        check[0] = true;
        for(int i3 = 1; i3<=n3; i3++) {
            for(int i1 = 0; i1 <= i3 && i1<=n1 ; i1++) {
                int i2 = i3-i1;
                
                if(i2>n2) {
                    continue;
                }
                cout << i1 << "，" <<i2 <<"，" << i3  <<std::endl;
                if(i1>=1 && check[i2] && s1[i1-1] == s3[i3-1]) {
                    check[i2] = true;
                    cout << i1 << "，" <<i2 <<"，" << i3  << "ok"<<std::endl;
                } else {
                    check[i2] = false;
                }
                if(i2>=1 && check[i2-1] && s2[i2-1] == s3[i3-1]) {
                    check[i2] = true;
                    cout << i1 << "，" <<i2 <<"，" << i3 << "ok"  <<std::endl;
                }
            }
        }
        return check[n2];
    }

    bool isInterleave2(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if(n1+n2 != n3) return false;
        auto check = vector<vector<int>>(n1+1 , vector<int>(n2+1, false));
        check[0][0] = true;
        for(int i3 = 1; i3<=n3; i3++) {
            for(int i1 = 0; i1 <= i3 && i1<=n1 ; i1++) {
                int i2 = i3-i1;
                
                if(i2>n2) {
                    continue;
                }
                cout << i1 << "，" <<i2 <<"，" << i3  <<std::endl;
                if(i1>=1 && check[i1-1][i2] && s1[i1-1] == s3[i3-1]) {
                    check[i1][i2] = true;
                    cout << i1 << "，" <<i2 <<"，" << i3  << "ok"<<std::endl;
                }
                if(i2>=1 && check[i1][i2-1] && s2[i2-1] == s3[i3-1]) {
                    check[i1][i2] = true;
                    cout << i1 << "，" <<i2 <<"，" << i3 << "ok"  <<std::endl;
                }
            }
        }
        return check[n1][n2];
    }
};