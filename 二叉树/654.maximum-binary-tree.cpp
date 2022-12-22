/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0)
            return nullptr;
        return createTree(nums, 0, nums.size() - 1);
    }

    TreeNode* createTree(const vector<int>& nums, int left, int right) {
        
        if (left > right)
        {
            return nullptr;
        }
        int maxIdx = left;
        for (size_t i = left; i < right + 1; i++)
        {
            maxIdx = nums[i] > nums[maxIdx] ? i : maxIdx;
        }
        TreeNode* root = new TreeNode(nums[maxIdx]);
        root->left = createTree(nums, left, maxIdx - 1);
        root->right = createTree(nums, maxIdx + 1, right);
        return root;
    }
};
// @lc code=end

