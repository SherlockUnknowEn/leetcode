/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        
        if (p == root || q == root)
            return root;

        TreeNode* a = lowestCommonAncestor(root->left, p, q);
        TreeNode* b = lowestCommonAncestor(root->right, p, q);
        if (a != nullptr && b != nullptr)
            return root;
        
        return a != nullptr ? a : b;
    }
};
// @lc code=end

