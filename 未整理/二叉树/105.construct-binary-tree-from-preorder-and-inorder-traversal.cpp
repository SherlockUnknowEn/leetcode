/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return nullptr;
        }
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
    }


    TreeNode* build(const vector<int>& preorder, 
        const vector<int>& inorder, 
        int rootIndex, int left, int right) {
        if (left < 0 || right > inorder.size() - 1)
        {
            return nullptr;
        }
        
        
        TreeNode* root = new TreeNode(preorder[rootIndex]);
        int mid = left;
        for (size_t i = left; i < right + 1; i++)
        {
            if (inorder[i] == preorder[rootIndex])
            {
                mid = i;
                break;
            }
        }
        int leftNums = mid - left;
        int rightNums = right - mid;
        if (leftNums > 0)
        {
            root->left = build(preorder, inorder, 
                rootIndex + 1, left, mid - 1);
        }
        
        if (rightNums > 0)
        {
            root->right = build(preorder, inorder, 
                rootIndex + 1 + leftNums, mid + 1, right);
        }
        
        return root;
    }
};
// @lc code=end

