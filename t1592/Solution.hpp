#include <string>
#include <iostream>
using  namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        int n = text.length();
        int numSpace = 0;
        int spaceIndex = n-1;
        int numWords = 0;
        int wordFlag = 0;
        for(int i = n-1; i >=0 ;--i){
            if(text[i] != ' ') { //遇到字母
                if(wordFlag == 0) {
                    wordFlag = 1;
                }
                if(numSpace>0) {
                    swap(text[i], text[spaceIndex]);
                    
                    if(i== 0) {
                        ++numWords;
                        spaceIndex -=2;
                    } else {
                        --spaceIndex;
                    }
                } else { // 末尾没有空格
                    --spaceIndex;
                }
                
                
            } else {
                if(wordFlag == 1) {
                    wordFlag = 0;
                    --spaceIndex;
                    ++numWords;
                }
                ++numSpace;
            } 
            
        }
        cout <<numSpace <<endl;
        cout <<numWords <<endl;
        cout << text <<endl;
        int spaceEveryWord = numSpace/max((numWords-1), 1);
        cout <<spaceIndex <<endl;
        
        int j = spaceIndex+2;
        spaceIndex = 0;
        for(; j< n; j++) {
            cout << text[j] <<endl;
            if(text[j] != ' ') {
                wordFlag = 1;
                if(j > spaceIndex) {
                    swap(text[j],text[spaceIndex]);
                    
                }
                spaceIndex++;
            } else {
                if(wordFlag == 1) {
                    wordFlag = 0;
                    spaceIndex += (spaceEveryWord);
                }
            }
        }
        return text;
    }
};