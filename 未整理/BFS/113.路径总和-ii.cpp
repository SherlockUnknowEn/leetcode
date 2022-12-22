/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> ans;
        traceback(root, targetSum, 0, path, ans);
        return ans;
    }

    void traceback(TreeNode* root, int targetSum, int sum, vector<int>& path, vector<vector<int>>& ans) {
        if (root == nullptr)    return;
        sum += root->val;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && sum == targetSum)
        {
            ans.push_back(path);
        }
        traceback(root->left, targetSum, sum, path, ans);
        traceback(root->right, targetSum, sum, path, ans);
        path.pop_back();
    }
};
// @lc code=end

