#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include "../tree_struct.h"
using namespace std;

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        
        dfs(1, root);
        return val;
    }
    void dfs(int curdeepth, TreeNode* node) {
        if(curdeepth > deepth) {
            deepth = curdeepth;
            val = node->val;
        }
        if(node->left) {
            dfs(curdeepth+1, node->left);
        }
        if(node->right) {
            dfs(curdeepth+1, node->right);
        }
    }

    int findBottomLeftValue2(TreeNode* root) {
        if(root ==nullptr)
            return 0;
        deque<TreeNode*> que;
        que.push_back(root);
        int ans = 0;
        while(!que.empty()) {
            int n =que.size();
            for(int i=0; i<n;i++) {
                TreeNode* curNode = que.front();
                que.pop_front();
                if(i == 0) {
                    ans = curNode->val;
                }
                if(curNode->left)
                    que.emplace_back(curNode->left);
                if(curNode->right)
                    que.emplace_back(curNode->right);
            }
        }
        
        return ans;
    }
private:
    int val;
    int deepth;
};