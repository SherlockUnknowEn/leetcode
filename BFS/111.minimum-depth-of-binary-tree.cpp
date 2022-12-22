/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        
        queue<TreeNode*> q;
        int depth = 1;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode* a = q.front();
                q.pop();
                if (a->left == nullptr && a->right == nullptr)
                {
                    return depth;
                }
                if (a->left != nullptr)
                {
                    q.push(a->left);
                }
                if (a->right != nullptr)
                {
                    q.push(a->right);
                }
            }
            depth++;
        }
        return depth;
    }
};
// @lc code=end

