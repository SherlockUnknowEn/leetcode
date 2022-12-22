/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        
        // ListNode* graud = new ListNode();
        // graud->next = head;
        ListNode* fast = head;
        ListNode* mid = head;
        TreeNode* left_child = nullptr;
        TreeNode* right_child = nullptr;
        // 左子树
        while (fast != nullptr && fast->next != nullptr) {
            printf("%d", mid->val);
            TreeNode* tmp = new TreeNode(mid->val);
            tmp->left = left_child;
            left_child = tmp; // 头插法
            mid = mid->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(mid->val); // 根节点
        root->left = left_child;
        mid = mid->next;
        // 右子树
        while (mid != nullptr)
        {
            printf("%d", mid->val);
            TreeNode* tmp = new TreeNode(mid->val);
            tmp->left = right_child;
            right_child = tmp;
            mid = mid->next;
        }
        root->right = right_child;
        return root;

        //[0,1,2,3,4,5]
        //[3,2,5,1,null,4,null,0]
        //[3,1,5,0,2,4]
    }
};
// @lc code=end

