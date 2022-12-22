/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int sumNumbers(TreeNode* root) {
        if (root == nullptr)    return 0;
        int sum = 0;
        traceback(root, sum, 0);
        return sum;
    }

    void traceback(TreeNode* root, int& sum, int num) {
        if (root == nullptr) return;
        num = num * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            sum += num;
        }
        traceback(root->left, sum, num);
        traceback(root->right, sum, num);
    }
};
// @lc code=end

