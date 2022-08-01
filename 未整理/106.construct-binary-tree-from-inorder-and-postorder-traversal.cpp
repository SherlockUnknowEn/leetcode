/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0)
        {
            return nullptr;
        }
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* build(const vector<int>& inorder, 
        const vector<int>& postorder, 
        int inleft, int inright, 
        int postleft, int postright) {
        if (inleft < 0 || inright > inorder.size() - 1)
        {
            return nullptr;
        }
        // 后续遍历  最后一个元素  postright 为根节点
        int mid = inleft;
        for (size_t i = inleft; i < inright + 1; i++)
        {
            if (inorder[i] == postorder[postright])
            {
                mid = i;
                break;
            }
        }
        int leftNums = mid - inleft;
        int rightNums = inright - mid;
        TreeNode* root = new TreeNode(postorder[postright]);

        if (leftNums > 0)
        {
            root->left = build(inorder, postorder, inleft, mid - 1, postleft, postleft + leftNums - 1);
        }
        if (rightNums > 0)
        {
            root->right = build(inorder, postorder, mid + 1, inright, postleft + leftNums, postright - 1);
        }
       
        
        return root;
    }
};
// @lc code=end

