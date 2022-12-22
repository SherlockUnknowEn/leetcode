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

//     8
//    3     10
//   1  6     14
// -1 2 4 7 13
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
         
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        if (root->val == key)
        {
            // 1. 叶子节点直接删除
            if (root->left == nullptr && root->right == nullptr)
                return nullptr;
            // 2. 其中一半子树为null
            if (root->left == nullptr || root->right == nullptr)
                return root->left == nullptr ? root->right : root->left;        

            // 4. 左右子树都存在，在左子树中找最大的节点，替换为根节点
            TreeNode* target = root->left;
            while (target->right != nullptr)
            {
                target = target->right;
            }            
            root->left = deleteNode(root->left, target->val);
            target->left = root->left;
            target->right = root->right;
            return target;
        }
        return root;
    }



};
// @lc code=end

