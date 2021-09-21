#include <vector>
#include <list>
#include <queue>
#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
    int x,y;
    int rest;
    Node(int _x, int _y , int _rest) : x(_x), y(_y), rest(_rest) {}
    Node() = default;

};


class Solution {
    int m;
    int n;
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        return -1;
    }

    int shortestPathByDFS(vector<vector<int>>& grid, int k) {
       
        return -1;
    }

    int shortestPathByBFS(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        if(k>=m+n-3)
            return m+n-2;
        queue<Node> que;
        list<pair<int, int >> path;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k+1,false)));
        que.emplace(Node(0,0,k));
        visited[0][0][k] = true;
        int pathlen = 0;
        while (!que.empty())
        {
            for(int i = que.size(); i>0; i--)
            {
                Node node = que.front();
                que.pop();

                if (node.x == m-1 && node.y == n-1)
                {
                    cout << "find!"  <<endl;
                    return pathlen;
                }
                for (auto nextNode : getNextNodes(node, grid))
                {
                    if(visited[nextNode.x][nextNode.y][nextNode.rest])
                        continue;
                    visited[nextNode.x][nextNode.y][nextNode.rest] = true;
                    que.emplace(nextNode);
                    cout << "ADD: (" <<nextNode.x << ", " 
                        << nextNode.y << ", "<<nextNode.rest 
                        << ")"<< endl;
                }
            }
            pathlen++;
            cout << "pathLen: " <<pathlen << endl;
        }
        return -1;
    }

    vector<Node> getNextNodes(Node& node, vector<vector<int>>& grid )
    {
        vector<Node> nextNodes;
        int x = node.x;
        int y = node.y;
        int rest = node.rest;
        if(isInGrid(x+1, y)) {
            if( grid[x+1][y] == 0)
                nextNodes.push_back(Node(x+1, y, rest));
            else if(rest>0)
                nextNodes.push_back(Node(x+1, y, rest-1));
        } 

        if(isInGrid(x-1, y)) {
            if( grid[x-1][y] == 0)
                nextNodes.push_back(Node(x-1, y, rest));
            else if(rest>0)
                nextNodes.push_back(Node(x-1, y, rest-1));
        } 

        if(isInGrid(x, y+1)) {
            if( grid[x][y+1] == 0)
                nextNodes.push_back(Node(x, y+1, rest));
            else if(rest>0)
                nextNodes.push_back(Node(x, y+1, rest-1));
        } 
        if(isInGrid(x, y-1)) {
            if( grid[x][y-1] == 0)
                nextNodes.push_back(Node(x, y-1, rest));
            else if(rest>0)
                nextNodes.push_back(Node(x, y-1, rest-1));
        }
        return nextNodes;
    }

    bool isInGrid(int x,int y)
    {
        if( x >= 0 &&
            x <  m &&
            y >= 0 &&
            y <  n
        )   return true;
        return false;
    }

};

// unordered_map<pair<int,int >, bool> visited(make_pair(0,0) ,true);