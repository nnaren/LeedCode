#include <iostream>
#include <unordered_set>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> city2index(n);
        for(int i=0;i<n-1;i++) {
            city2index[connections[i][0]].push_back(i);
            city2index[connections[i][1]].push_back(i);
        }
        int reorderNum =0;
        vector<bool> visited(connections.size(), false);
        deque<int> que;  // 已处理的城市
        que.push_back(0);
        while(!que.empty()) {
            int cityIndex = que.front();
            que.pop_front();
            for(auto & roadIndex : city2index[cityIndex])
            {
                if(visited[roadIndex])
                    continue;
                visited[roadIndex] = true;
                if(connections[roadIndex][1] == cityIndex) {
                    que.push_back(connections[roadIndex][0]);
                    cout << "找到城市：" << connections[roadIndex][0] << endl;
                }
                if(connections[roadIndex][0] == cityIndex) {
                    reorderNum++;
                    que.push_back(connections[roadIndex][1]);
                    cout << "找到城市：" << connections[roadIndex][1] << endl;
                }
            }
        }
        return reorderNum;
    }


    int minReorder2(int n, vector<vector<int>>& connections) {
        deque<int> unusedRoad;
        unordered_set<int> connectedCity;
        int changeNum = 0;
        for(int i = 0 ; i<n-1 ;i++) {
            if(connections[i][0] == 0) {
                connectedCity.insert(connections[i][1]);
                changeNum++;
                continue;
            }
            if(connections[i][1] == 0) {
                connectedCity.insert(connections[i][0]);
                continue;
            }
            unusedRoad.push_back(i);
        }
        while(!unusedRoad.empty()) {
            int num = unusedRoad.size();
            for(int i=0;i<num;i++){
                int roadIndex = unusedRoad.front();
                unusedRoad.pop_front();
                if(connectedCity.count(connections[roadIndex][0]) >0) {
                    connectedCity.insert(connections[roadIndex][1]);
                    changeNum++;
                } else if(connectedCity.count(connections[roadIndex][1]) >0) {
                    connectedCity.insert(connections[roadIndex][0]);
                } else {
                    unusedRoad.push_back(roadIndex);
                }
                
            }
            
            
        }
        return changeNum;

    }
};

// 超时 ：