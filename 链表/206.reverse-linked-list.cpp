/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    // ListNode* reverseList(ListNode* head) {
    //     if (head == nullptr)
    //         return nullptr;
    //     if (head->next == nullptr)
    //         return head;
    //     ListNode* last = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = nullptr;
    //     return last;
    // }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next;
        while (cur != nullptr)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
// @lc code=end

