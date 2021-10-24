//
// Created by Percy on 2021/10/24.
//

#ifndef T102_SOLUTION_H
#define T102_SOLUTION_H
#include <queue>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int curLevelSize = que.size();
            result.push(vector<int> ());

            for(int i=0;i<curLevelSize;i++)
            {
                auto cur = que.front(); que.pop();
                result.back().push_back(cur->val);
                if(cur.left)  que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }

        }
        return result;
    }
};
#endif //T102_SOLUTION_H
