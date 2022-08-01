/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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

//  5
// 1 4
//  3 6
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
            return true;
        
        long min = LONG_MIN;
        bool r = true;
        valid(root, min, r);
        return r;
    }

    void valid(TreeNode* root, long& min, bool& r) {
        if (root == nullptr) return;
        if (!r) return;
        valid(root->left, min, r);
        if (root->val <= min)
        {
            r = false;
            return;
        }
        min = root->val;
        valid(root->right, min, r);
    }
};
// @lc code=end

