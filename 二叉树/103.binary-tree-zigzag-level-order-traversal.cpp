/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>();
        vector<vector<int>> res;
        stack<TreeNode*> stk;
        queue<TreeNode*> q;
        stk.push(root);
        bool dirct = true; // 规定从左往右是true
        while (!stk.empty())
        {
            int sz = stk.size();
            vector<int> layer;
            for (int i = 0; i < sz; i++)
            {
                TreeNode* n = stk.top();
                stk.pop();
                q.push(n);
                layer.push_back(n->val);
            }
            for (int i = 0; i < sz; i++)
            {
                TreeNode* n = q.front();
                q.pop();
                if (dirct)
                {
                    if (n->left != nullptr)
                    {
                        stk.push(n->left);
                    }
                    if (n->right != nullptr)
                    {
                        stk.push(n->right);
                    }
                }
                else
                {
                    if (n->right != nullptr)
                    {
                        stk.push(n->right);
                    }
                    if (n->left != nullptr)
                    {
                        stk.push(n->left);
                    }
                }
            }
            dirct = !dirct;
            res.push_back(layer);
        }
        return res;
    }
};
// @lc code=end

