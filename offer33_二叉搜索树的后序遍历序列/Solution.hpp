#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return dfs(postorder, 0, postorder.size()-1);
    }
    bool dfs(vector<int>& postorder, int i, int j) {
        if(i>=j) // 该子树不存在，或者该子树只有一个节点。
            return true;
        int point = i;
        while(postorder[point] < postorder[j])
            point++;
        int mid = point;
        while(postorder[point] > postorder[j])
            point++;
        return (point==j) && dfs(postorder, i, mid-1) && dfs(postorder, mid,j-1);
    }

    bool verifyPostorder2(vector<int>& postorder) { 
        stack<int> st;
        int root = INT_MAX;
        for(int i = postorder.size()-1; i>=0;i--) {
            cout << "i , v " << i <<"," << postorder[i]<< endl;  
            if(postorder[i] > root) return false;  //  所有值要比root 小 ？
            
            while(!st.empty() && st.top() > postorder[i]) { // 去掉比当前大的，单调递增。 存在最小值
                root = st.top();
                cout << "root = " << root << endl;
                st.pop();
            }
            st.push(postorder[i]);
        }
        return true;
    }
};