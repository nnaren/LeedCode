#include <vector>
#include <list>
#include <queue>
#include <iostream>
#include <unordered_set>
using namespace std;



class Solution {

private:
    list<int> path;
    vector<int>* ans;
    vector<vector<int>>* _red_edge;
    vector<vector<int>>* _blue_edge;
public:


    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edge, vector<vector<int>>& blue_edge) {

        queue<int> que;
        
        _red_edge = &red_edge;
        _blue_edge = &blue_edge;
        ans = new vector<int>(n,-1);
        // list<pair<int, int >> path;
        // unordered_set<Node> visited;
        // list<int> path;
        que.push(0);
        (*ans)[0] = 0;
        // visited.insert(0);
        backtracking(0,true);
        backtracking(0,false);
   
        return vector<int>();
    }
    void backtracking(int start,  bool isRed)
    {
        // if (row == n)
        // {
            
        //     return;
        // }
        if(isRed)
        {
            for (auto edge : *_red_edge)
            {
                if(edge[0] != start)
                    continue;
                int end = edge[1];
                if((*ans)[end] == -1 || (*ans)[end] > path.size())
                    ans->at(end) = path.size();
                path.push_back(end);
                backtracking(end, false);
                path.push_back(end); 
            }
        }
        else{
            for (auto edge : *_blue_edge)
            {
                if(edge[0] != start)
                    continue;
                int end = edge[1];
                if((*ans)[end] == -1 || (*ans)[end] > path.size())
                    ans->at(end) = path.size();
                path.push_back(end);
                backtracking(end, false);
                path.push_back(end); 
            }
        }
    }
  
};
