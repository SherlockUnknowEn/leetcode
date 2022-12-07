/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr)
            return {};
        queue<TreeNode*> qe;
        qe.push(root);
        stack<vector<int>> stk;
        vector<vector<int>> ans;
        while (!qe.empty()) {
            int sz = qe.size();
            vector<int> level(sz);
            for (int i = 0; i < sz; i++) {
                TreeNode* n = qe.front();
                qe.pop();
                level[i] = n->val;
                if (n->left != nullptr)
                    qe.push(n->left);
                if (n->right != nullptr)
                    qe.push(n->right);
            }
            stk.push(level);
        }
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};
// @lc code=end

