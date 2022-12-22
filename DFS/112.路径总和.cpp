/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return traceback(root, targetSum, sum);
    }

    bool traceback(TreeNode* root, int targetSum, int sum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr)
            return (sum + root->val) == targetSum;
        return traceback(root->left, targetSum, sum + root->val) ||
                traceback(root->right, targetSum, sum + root->val);
        
    }   
};
// @lc code=end

