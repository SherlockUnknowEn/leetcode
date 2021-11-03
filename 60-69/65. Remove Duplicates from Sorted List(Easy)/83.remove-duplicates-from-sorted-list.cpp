/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-999);
        ListNode *d = dummy;
        dummy->next = head;
        ListNode *p = head;
        while (p != nullptr)
        {
            if (d->val != p->val)
            {
                d->next = p;
                d = p;
            }
            p = p->next;
        }
        d->next = p; // 最后一个重复的节点删除
        return dummy->next;
    }
};
// @lc code=end

