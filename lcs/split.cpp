#include<string>
#include<vector>
#include<string.h>
std::vector<std::string> SplitString(std::string str, const char* c)
{
    std::vector<std::string> v;
    size_t strLen = str.length();
    size_t strArrSize = strLen + 1;
    char* tempstr = new(std::nothrow) char[strArrSize];
    if(NULL == tempstr)
    {
        return v;
    }

    char* p =NULL;
    char* outPtr=NULL;
    strncpy(tempstr, str.c_str(), strLen);
    tempstr[strLen]= '\0';
    p = strtok(tempstr, c);
    while (p !=NULL && p!= (void*)-1)
    {
        v.push_back(p);
        p = strtok((char*)NULL, c);
    }
    delete[] tempstr;
    tempstr = NULL;
    return v;
}