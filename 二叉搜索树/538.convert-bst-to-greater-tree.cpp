/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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

    TreeNode* convertBST(TreeNode* root) {
        int plus = 0;
        cvtBT(root, plus);
        return root;
    }

    void cvtBT(TreeNode* root, int& plus) {
        if (root == nullptr) return;
        
        cvtBT(root->right, plus);
        root->val = root->val + plus;
        plus = root->val;
        cvtBT(root->left, plus);
    }
};
// @lc code=end

