/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<TreeNode*> generateTrees(int n) {
        return subTree(1, n);
    }

    vector<TreeNode*> subTree(int left, int right) {
        if (left > right) return { nullptr };
        
        vector<TreeNode*> ans;
        for (int i = left; i <= right; i++) {
            vector<TreeNode*> left_tree = subTree(left, i - 1);
            vector<TreeNode*> right_tree = subTree(i+1, right);
            for (int j = 0; j < left_tree.size(); j++) {
                for (int k = 0; k < right_tree.size(); k++) {
                    TreeNode* node =  new TreeNode(i);
                    node->left = left_tree[j];
                    node->right = right_tree[k];
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }

};
// @lc code=end

