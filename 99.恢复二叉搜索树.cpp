/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void swap(TreeNode* a, TreeNode* b) {
        int v = a->val;
        a->val = b->val;
        b->val = v;
    }

    void recoverTree(TreeNode* root) {
        traverse(root);
        TreeNode *first, *second;
        for (int i = 0; i < vec.size() - 1; i++) {
            if (vec[i]->val > vec[i + 1]->val) {
                first = vec[i];
                break;
            }
        }
        for (int i = vec.size() - 1; i >= 1; i--) {
            if (vec[i]->val < vec[i - 1]->val) {
                second = vec[i];
                break;
            }
        }
        swap(first, second);
    }

    void traverse(TreeNode* root) {
        if (root == nullptr) return;

        traverse(root->left);

        vec.push_back(root);
        // mp[root->val] = root;

        traverse(root->right);
    }

private:
    // unordered_map<int, TreeNode*> mp;
    vector<TreeNode*> vec;
};
// @lc code=end

