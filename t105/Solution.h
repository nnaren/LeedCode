//
// Created by Percy on 2021/10/24.
//

#ifndef T105_SOLUTION_H
#define T105_SOLUTION_H
#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> indexInOrder;
    // 3 9 20 15 7
    // 9 3 15 20 7
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < preorder.size(); ++i) {
            indexInOrder[inorder[i]] = i;
        }
        TreeNode* root = createChildTree(preorder, inorder,0,preorder.size(),0,preorder.size());
        return root;
    }

    TreeNode *
    createChildTree(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd)
    {
        if(preStart == preEnd)
        {
            return nullptr;
        }
        int val = preorder[preStart];
        TreeNode* root = new TreeNode(val);
        int  index = indexInOrder[val];
        int leftTreeSize = index - inStart;
        root->left = createChildTree(preorder, inorder, preStart+1, preStart+1+leftTreeSize, inStart, index);
        root->right = createChildTree(preorder, inorder, preStart+1+leftTreeSize, preEnd, index+1, inEnd);
        return root;
    }
};
#endif //T105_SOLUTION_H
