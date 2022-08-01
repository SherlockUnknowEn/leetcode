/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        if (key > root->val) 
        {
            root->right = deleteNode(root->right, key);
        }
        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        if (root->left == nullptr || root->right == nullptr)
            return root->left == nullptr ? root->right : root->left;
        // 从左子树找到最大的节点，替换本节点
        TreeNode* a = root->left;
        while (a->right != nullptr)
        {
            a = a->right;
        }
        // 删除那个节点
        root->right = deleteNode(root->left, a->val);
        a->left = root->left;
        a->right = root->right;
        return root;
    }
};
// @lc code=end

