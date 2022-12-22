/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        queue<TreeNode*> qe;
        qe.push(root);
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
            ans.push_back(level);
        }
        return ans;
    }
};
// @lc code=end

