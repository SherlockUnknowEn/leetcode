/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> qe;
        qe.push(root);
        vector<int> ans;
        while (!qe.empty()) {
            int sz = qe.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* n = qe.front();
                qe.pop();
                if (i == 0)
                    ans.emplace_back(n->val);
                if (n->right != nullptr)
                    qe.push(n->right);
                if (n->left != nullptr)
                    qe.push(n->left);
            }
        }
        return ans;
    }
};
// @lc code=end

