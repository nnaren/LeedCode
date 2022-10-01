#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1!=n2) return false;
        if (n1==0)
        {
            return true;
        }
        
        int same = 0;
        int i =0, j =0;
        while (j<2*n1)
        {
            if(s1[i]==s2[j]){
                i++;
                j++;
                same ++;
                if(same== n1) return true;
            } else {
                s2+=s2.substr(j-same,same+1);
                same=0;
                i=0;
                j++;
            }

        }
        return false;
    }
};