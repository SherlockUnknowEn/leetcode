/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }

    void dfs(TreeNode* root, int path, int& sum) {
        if (root == nullptr)
            return;
        int val = (path << 1) | root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += val;
        }
        dfs(root->left, val, sum);
        dfs(root->right, val, sum);
    }

};
// @lc code=end

