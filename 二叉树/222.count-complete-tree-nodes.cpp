/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int lh = 0;
        int rh = 0;
        // 计算左右子树的高度
        TreeNode* n = root;
        while (n != nullptr)
        {
            lh++;
            n = n->left;
        }
        n = root;
        while (n != nullptr)
        {
            rh++;
            n = n->right;
        }
        if (rh == lh)
            return pow(2, rh) - 1;
        // 左右子树肯定有某一个是满二叉树 可以降低时间复杂度
        return 1 + countNodes(root->left) + countNodes(root->right);
        
    }
};
// @lc code=end

