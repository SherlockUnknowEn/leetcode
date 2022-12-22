/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return genBST(nums, 0, nums.size() - 1);
    }

    TreeNode* genBST(vector<int>& nums, int begin, int end) {
        if (begin > end) return nullptr;
        int mid = (end + begin) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = genBST(nums, begin, mid-1);
        root->right = genBST(nums, mid+1, end);
        return root; 
    }
};








// @lc code=end

