#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {        
        return dfs(root, root->val, root->val);
    }
    int dfs(TreeNode* cur, int bigRootValue, int littleRootValue){
        if(cur==nullptr) {
            return -1;
        }
        int ans = abs(bigRootValue - cur->val);
        int ans2 = abs(littleRootValue - cur->val);
        ans = max(ans, ans2);
        bigRootValue = max(bigRootValue, cur->val);
        littleRootValue = min(littleRootValue, cur->val);
        int left = dfs(cur->left, bigRootValue, littleRootValue);
        int right = dfs(cur->right, bigRootValue, littleRootValue);
        
        return max(ans, max(left,right));
    }
};