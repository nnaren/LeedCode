#include <vector>
#include <list>
#include <queue>
#include <iostream>
#include <unordered_set>
using namespace std;
namespace std
{
struct Node
{
    int x,y;
    int rest;
    Node(int _x, int _y , int _rest) : x(_x), y(_y), rest(_rest) {}
    Node() = default;
    bool operator==(const Node& rc)  const {
        return x == rc.x && y == rc.y && rest == rc.rest ;
    }
    bool operator<(const Node& rc)  const {
        
        return (x == rc.x) ? (  ( y== rc.y) ? rest < rc.rest : y<rc.y  ) : (x < rc.x) ;
    }
    size_t operator()(const Node& rc) const {
        return hash<int>()(rc.x) ^ hash<int>()(rc.rest) ^ hash<int>()(rc.rest) ;
    }
};

// struct Node_Hash
// {
//     size_t operator()(const Node& rc) const {
//         return hash<int>()(rc.x) ^ hash<int>()(rc.rest) ^ hash<int>()(rc.rest) ;
//     }
// };
// struct Node_equal
// {
//     bool operator()(const Node& rc1, const Node& rc2) const noexcept
//     {
//         return rc1.x == rc2.x && rc1.y == rc2.y && rc1.rest == rc2.rest;
//     }

// };

// 模板特化
template <>
struct hash<Node>
{
    size_t operator()(const Node& rhs) const {
        return hash<int>()(rhs.x) ^ hash<int>()(rhs.rest) ^ hash<int>()(rhs.rest) ;
    }
};


// bool operator==(const Node& lhs, const Node& rhs)  {
//     return lhs.x == rhs.x && lhs.y == rhs.y && lhs.rest == rhs.rest ;
// }

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
        unordered_set<Node> visited;
        que.push(Node(0,0,k));
        visited.insert(Node(0,0,k));
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
                    if(visited.count(nextNode))
                        continue;
                    visited.insert(nextNode);
                    que.push(nextNode);
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
}
// unordered_map<pair<int,int >, bool> visited(make_pair(0,0) ,true);