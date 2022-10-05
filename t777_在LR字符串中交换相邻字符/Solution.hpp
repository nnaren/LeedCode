#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        int i = 0;
        int j = 0;
        while(j < end.size() && i < start.size()){
            if(end[j] == 'L') {
                while(i < start.size()) {
                    if(start[i] == 'L') {
                        if(i<j) return false;
                        i++;
                        break;
                    } else if(start[j] == 'R'){
                        return false;
                    } else {
                        i++;
                        if(i == start.size()) {
                            return false;
                        }
                    }
                    
                }
                
            } else if(end[j] == 'R') {
                while(i < start.size()) {
                    if(start[i] == 'R') {
                        if(i>j) return false;
                        i++;
                        break;
                    } else if(start[j] == 'L'){
                        return false;
                    } else {
                        i++;
                        if(i == start.size()) {
                            return false;
                        }
                    }
                }
            }
            j++;
        }
        while(i < start.size()) {
            if(start[i] != 'X')
                return false;
            i++;
        }
        while(j < end.size()) {
            if(end[j] != 'X')
                return false;
            j++;
        }
        return true;
    }
};