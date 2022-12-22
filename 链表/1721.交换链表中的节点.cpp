/*
 * @lc app=leetcode.cn id=1721 lang=cpp
 *
 * [1721] 交换链表中的节点
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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* p1 = dummy;
        for (int i = 0; i < k; i++) {
            p1 = p1->next;
        }
        ListNode* p2 = dummy;
        ListNode* fast = p1;
        while (fast != nullptr) {
            fast = fast->next;
            p2 = p2->next;
        }
        int t = p1->val;
        p1->val = p2->val;
        p2->val = t;
        return head;
    }
};
// @lc code=end

