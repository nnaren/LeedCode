#include<string>
#include<string.h>
#include<iostream>
#include<ext/hash_map>
using namespace __gnu_cxx;
using namespace std;

extern std::vector<std::string> SplitString(std::string str, const char* c);

string lcsUseMap(string str1, string str2)
{
    if(str1.empty() || str2.empty())
    {
        return "-1";
    }

    const int lengthStr1 = str1.length();
    const int lengthStr2 = str2.length();
    char strArry1[40];
    char strArry2[40];
    strcpy(strArry1, str1.c_str());
    strcpy(strArry2, str2.c_str());

    hash_map<char, string> char2Map;
    for(int i=0; i<lengthStr2;i++)
    {
        if(char2Map.find(strArry2[i]) != char2Map.end())
        {
            char2Map[strArry2[i]] = char2Map[strArry2[i]] + "," + to_string(i);
            cout << strArry2[i] << ":" << char2Map[strArry2[i]] <<endl;
        }
        else
        {
            char2Map[strArry2[i]] = to_string(i);
            cout << strArry2[i] << ":" << char2Map[strArry2[i]] <<endl;
        }
    }

    int maxLength = 0, maxIndex = 0;
    for(int i=0; i<lengthStr1; i++)
    {
        if(char2Map.find(strArry1[i]) != char2Map.end())
        {
            vector<string> indexList = SplitString(char2Map[strArry1[i]],",");
            for(auto indexStr2: indexList)
            {
                int index2 = atoi(indexStr2.c_str());
                int tempIndex1 = i;
                int tempLength = 0;
                while (index2 < lengthStr2 && tempIndex1 < lengthStr1 &&
                strArry2[index2] == strArry1[tempIndex1])
                {
                    tempLength++;
                    index2++;
                    tempIndex1++;
                }
                if(tempLength > maxLength)
                {
                    maxIndex = i;
                    maxLength = tempLength;
                }
            }
        }
       
    }
    if(maxLength == 0)
        return "-1";
    return str1.substr(maxIndex, maxLength);
}