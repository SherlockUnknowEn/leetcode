/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int _ = getSum(root);
        int max_count = -1;
        for (auto& kv : memo) {
            max_count = max(max_count, kv.second);
        }
        vector<int> ans;
        for (auto& kv : memo) {
            if (kv.second == max_count) {
                ans.push_back(kv.first);
            }
        }
        return ans;
    }

    int getSum(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        int sum = root->val + getSum(root->left) + getSum(root->right);
        memo[sum]++;
        return sum;
    }

private:
    unordered_map<int, int> memo;
};
// @lc code=end

