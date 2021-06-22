#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    vector<string> vHour;
    vector<string> vMin;
    vector<string> time;
public:
    vector<string> readBinaryWatch(int turnedOn) 
    {
     
        if(turnedOn > 8)
            return time;
        int x = min(turnedOn,3);
        for(int i=0; i <= x; i++)
        {
            dfsHour(i,0,0,0);
            dfsMin(turnedOn-i, 0, 0,0);
            for (int i = 0 ; i < vHour.size(); i++)
            {
                for (int j = 0; j < vMin.size(); j++)
                {
                    time.push_back(vHour[i]+":"+vMin[j]);
                }
            }
            vHour.clear();
            vMin.clear();
        }
        return time;
        

        
    }
    void dfsHour(int n, int used, int pick, int hour)
    {
        
        if(used >= n)
        {   
            if(hour < 12)    
                vHour.push_back(to_string(hour));
            return;
        }
        int bits =  pick>0 ? ((~(pick*2-1)) & (15)) : 15;
        while (bits>0)
        {
            int pick = bits & (-bits) ;
            dfsHour(n, used+1,pick,pick|hour);
            bits &= (bits-1);
        }
        
        
    }
    void dfsMin(int n, int used,int pick,int min)
    {
        
        if(used >= n)
        {
            if(min<10)
                vMin.push_back("0"+to_string(min));
            else if(min>=10 && min<60)
                vMin.push_back(to_string(min));
            return;
        }

        int bits =  pick>0 ? ((~(pick*2-1)) & (63)) : 63;
        while (bits>0)
        {
            int pick = bits & (-bits) ;
            dfsMin(n, used+1, pick,pick|min);
            bits &= (bits-1);
        }
        
        
    }
    
};

