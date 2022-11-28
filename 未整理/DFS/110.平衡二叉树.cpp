/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        return dfs(root) != -1;
    }

    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int a = dfs(root->left);
        int b = dfs(root->right);
        if (a == -1 || b == -1) return -1;
        if (abs(a-b) > 1) return -1;
        return max(a, b) + 1;        
    }
};
// @lc code=end

