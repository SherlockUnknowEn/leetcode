/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        int cur = 0;
        int output = -1;
        search(root, k, cur, output);
        return output;
    }
    
    void search(TreeNode* root, int k, int& cur, int& output) {
        if (root == nullptr) return;
        if (cur >= k) return;
        
        search(root->left, k, cur, output);
        cur++;
        if (cur == k)
        {
            output = root->val;
            return;
        }
        search(root->right, k, cur, output);
    }
};
// @lc code=end

