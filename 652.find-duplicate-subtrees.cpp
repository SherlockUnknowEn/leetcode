/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (root == nullptr)
            return r;
        stringify(root);
        return r;
        
    }

    string stringify(TreeNode* root) {
        if (root == nullptr)
        {
            return "#";
        }
        string left = stringify(root->left);
        string right = stringify(root->right);

        string me = left + "," + right + "," + to_string(root->val); // 中序遍历会有问题  #,0,#,0  不唯一
        auto a = count.find(me);
        if (a == count.end())
        {
            count.insert({ me, 1 });
        } 
        else
        {
            a->second = a->second + 1;
            if (a->second == 2)
            {
                r.push_back(root);
            }
        }
        return me;
    }

private:
    unordered_map<string, int> count;
    vector<TreeNode*> r;
};
// @lc code=end

