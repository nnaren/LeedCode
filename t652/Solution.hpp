#include <iostream>
#include "../tree_struct.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return {ans.begin(), ans.end()};
    }

    string dfs(TreeNode* root) {
        if(!root) {
            return "";
        }
        string serial = to_string(root->val) + "("+dfs(root->left) +")" +"(" + dfs(root->right) +")";
        auto it = visited.find(serial);
        if(it != visited.end()) {
            ans.insert(it->second);
        } else {
            visited[serial] = root;
        }
        return serial;
    }

private:
    unordered_map<string, TreeNode*> visited;
    unordered_set<TreeNode*> ans;
};