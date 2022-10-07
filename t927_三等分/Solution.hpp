#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int numOne = 0; 
        string num_s;
        for(auto & a : arr) {
            num_s += to_string(a);
            if(a == 1 ) {
                numOne++;
            }
        }
        cout << num_s << endl;
        if(numOne%3 != 0)
            return {-1,-1};
        int firstpart = numOne/3;
        int point1=-1;
        int point1_2 = -1;

        int secondPart = numOne/3*2;
        int point2=-1;
        int point2_2 = -1;

        int lastZeroNum = -1;
        int i_one=numOne;
        for(int i=arr.size()-1; i>=0; i--) { 
            if(lastZeroNum == -1 && arr[i] == 1) {
                lastZeroNum = arr.size() -1- i;
            }
            if(arr[i]) {
                if(point1 == -1 && firstpart == i_one) {
                    point1 =i;
                }
                if(point1_2 == -1 && firstpart+1 == i_one) {
                    point1_2 =i;
                }
                if(point2 == -1 &&secondPart == i_one) {
                    point2 =i;
                }
                if(point2_2 == -1 && secondPart+1 == i_one) {
                    point2_2 =i;
                }
                i_one--;
            }
            
        }
        cout << point1 << "," << point1_2 << "," << point2 << "," << point2_2 << "," << lastZeroNum << endl;
        //更新位置
        point1 += lastZeroNum;
        point2 += lastZeroNum;
        if(point1 >= point1_2 || point2  >= point2_2)  {
            return {-1, -1};
        }
        string part1 = num_s.substr(0,point1+1);
        string part2 = num_s.substr(point1+1,point2-point1);
        string part3 = num_s.substr(point2+1);
        int n1 = part1.size();
        int n2 = part2.size();
        int n3 = part3.size();
        int min_size = min(part1.size(), min(part2.size(),part3.size()));
        part1 = part1.substr(n1 - min_size);
        part2 = part2.substr(n2 - min_size);
        part3 = part3.substr(n3 - min_size);
        // cout << part1 << "," << part2 << "," <<part3 << endl; ;
        if(part1.compare(part2)==0 && part2.compare(part3) == 0) {
            cout << point1 << "," << point2+1 << endl;
            return {point1, point2+1};
        }
        return {-1, -1};
    }
    vector<int> threeEqualParts2(vector<int>& arr) {
        // string s = "0100";
        // auto num = stoi(s, 0, 2);
        // cout <<num << endl;
        int numOne = 0; 
        string num_s;
        for(auto & a : arr) {
            num_s += to_string(a);
            if(a == 1 ) {
                numOne++;
            }
        }
        cout << num_s << endl;
        if(numOne%3 != 0)
            return {-1,-1};
        int firstpart = numOne/3;
        int point1=-1;
        int point1_2 = -1;

        int secondPart = numOne/3*2;
        int point2=-1;
        int point2_2 = -1;

        int lastZeroNum = -1;
        int i_one=numOne;
        for(int i=arr.size()-1; i>=0; i--) { 
            if(lastZeroNum == -1 && arr[i] == 1) {
                lastZeroNum = arr.size() -1- i;
            }
            if(arr[i]) {
                if(point1 == -1 && firstpart == i_one) {
                    point1 =i;
                }
                if(point1_2 == -1 && firstpart+1 == i_one) {
                    point1_2 =i;
                }
                if(point2 == -1 &&secondPart == i_one) {
                    point2 =i;
                }
                if(point2_2 == -1 && secondPart+1 == i_one) {
                    point2_2 =i;
                }
                i_one--;
            }
            
        }
        cout << point1 << "," << point1_2 << "," << point2 << "," << point2_2 << "," << lastZeroNum << endl;
        //更新位置
        point1 += lastZeroNum;
        point2 += lastZeroNum;
        if(point1 >= point1_2 || point2  >= point2_2)  {
            return {-1, -1};
        }
        int part1 = stoi(num_s.substr(0,point1+1),0,2);
        int part2 = stoi(num_s.substr(point1+1,point2-point1),0,2);
        int part3 = stoi(num_s.substr(point2+1),0,2);
        cout << part1 << part2 <<part3 ;
        if(part1 == part1 && part2 == part3) {
            // cout << point1 << "," << point2+1 << endl;
            return {point1, point2+1};
        }
        return {-1, -1};
    }
};