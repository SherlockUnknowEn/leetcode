/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<TreeNode*> path;
        dfs(root, path, ans);
        return ans;
    }

    void dfs(TreeNode* root, vector<TreeNode*>& path, vector<string>& ans) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            string s;
            for (auto node : path) {
                s =s + to_string(node->val) + "->";
            }
            s += to_string(root->val);
            ans.push_back(s);
        } else {
            path.push_back(root);
            dfs(root->left, path, ans);
            dfs(root->right, path, ans);
            path.pop_back();
        }
    }

};
// @lc code=end

