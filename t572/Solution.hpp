#include <iostream>
#include <vector>
#include <limits.h>
#include "../tree_struct.h"

using namespace std;

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
         //先当前节点，不行就子节点，
         return dfs(root, subRoot);
    }
    bool check(TreeNode* root, TreeNode* subRoot) {
        if (root==nullptr && subRoot==nullptr)  // 当前层都为空，为true， 迭代到最后
            return true;
        if ((root!=nullptr &&subRoot==nullptr ) || (root==nullptr &&subRoot!=nullptr) || (root->val != subRoot->val))   // 当前层  一个为空，另一个不为空【两种情况】；都不为空且不相对【一种情况】
            return false;
        // 都不为空，且相对
        return check(root->left, subRoot->left) && check(root->right, subRoot->right);
    }
    bool dfs(TreeNode* root, TreeNode* subRoot) {   // 按root的深度遍历检查 

        if(root == nullptr)
            return false; // 到叶子节点
        return  check(root, subRoot) || dfs(root->left, subRoot) || dfs(root->right, subRoot);;
    }

// ----------------------------------------------------------------
    
    void getMaxElement(TreeNode *o) {
        if (!o) {
            return;
        }
        maxElement = max(maxElement, o->val);
        getMaxElement(o->left);
        getMaxElement(o->right);
    }


    void getFirstOrder(TreeNode *o, vector <int> &tar) {
        if (!o) {
            return;
        }
        tar.push_back(o->val);
        if (o->left) {
            getFirstOrder(o->left, tar);
        } else {
            tar.push_back(lNull);
        }
        if (o->right) {
            getFirstOrder(o->right, tar);
        } else {
            tar.push_back(rNull);
        }
    }

    bool isSubtree2(TreeNode* root, TreeNode* subRoot) {
        maxElement = INT_MIN;
        getMaxElement(root);
        getMaxElement(subRoot);
        lNull = maxElement+1;
        rNull = maxElement+2;
        vector <int> rSeq, sSeq;
        getFirstOrder(root, rSeq);
        getFirstOrder(subRoot, sSeq);
        return kmp(rSeq, sSeq);

    }
    bool kmp(vector<int>& sOrder, vector<int>& tOrder) {
        
        int sLen = sOrder.size(), tLen = tOrder.size();
        vector <int> fail(tOrder.size(), -1);  // 先对匹配串进行研究
        for (int i = 1, j = -1; i < tLen; ++i) {
            while (j != -1 && tOrder[i] != tOrder[j + 1]) {
                j = fail[j];
            }
            if (tOrder[i] == tOrder[j + 1]) {
                ++j;
            }
            fail[i] = j;
        }
        for (int i = 0, j = -1; i < sLen; ++i) {
            while (j != -1 && sOrder[i] != tOrder[j + 1]) {
                j = fail[j];
            }
            if (sOrder[i] == tOrder[j + 1]) {
                ++j;
            }
            if (j == tLen - 1) {
                return true;
            }
        }
        return false;
    }


    int maxElement, lNull, rNull;
};