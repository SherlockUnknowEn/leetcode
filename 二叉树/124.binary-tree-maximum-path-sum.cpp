/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int maxValue = INT_MIN;
        childSum(root, maxValue);
        return maxValue;   
    }

    int childSum(TreeNode* root, int& maxValue) {
        if (root == nullptr)
        {
            return 0;
        }
        
        int left = childSum(root->left, maxValue);
        int right = childSum(root->right, maxValue);
        
        
        // max 记录后序遍历过程中的最大路径值
        // 最大路径可能为 
        // 1. 左子树
        // 2. 自身
        // 3. 右子树 
        // 4. 左子树 -> 自身
        // 5. 自身 -> 右子树
        // 6. 左子树 -> 自身 -> 右子树
        // if (root->left != nullptr)
        // {
        //     maxValue = max(left, maxValue);
        //     maxValue = max(left + root->val, maxValue);
        // }
        // if (root->right != nullptr)
        // {
        //     maxValue = max(right, maxValue);
        //     maxValue = max(right + root->val, maxValue);
        // }
        // if (root->left != nullptr && root->right != nullptr)
        // {
        //     maxValue = max(left + right + root->val, maxValue);
        // }
        // maxValue = max(root->val, maxValue);
        
        // 若 left right 小于0， 将其置为0，则可以统一上面6种情况
        if(left < 0) left = 0;
        if(right < 0) right = 0;
        maxValue = max(left + right + root->val, maxValue);
        
        // 从自身往父节点走，有三种选择，由于不可后退无法同时经过左右子树
        // 1. 自身 -> 父节点
        // 2. 左子树 -> 自身 -> 父节点
        // 3. 右子树 -> 自身 -> 父节点
        // 返回： 3种选择的最优解
        // int t = root->val;
        // int l = left + root->val;
        // int r = right + root->val;
        // t = max(l, t);
        // t = max(r, t);
        
        // 由于 left  right 最小值为 0， 可以将上面情况统一为 root + left 与 root + right 的比较 
        return max(left + root->val, right + root->val);
        // [5,4,8,11,null,13,4,7,2,null,null,null,1]
        // [1,null,2,null,3,null,4,null,5]
        // [9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6]
    }
};
// @lc code=end

