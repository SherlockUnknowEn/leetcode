/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        // if (head == nullptr) return nullptr;
        ListNode* dummy = new ListNode(999);
        dummy->next = head;
        ListNode* p = dummy;
        while (head != nullptr)
        {
            if (head->val != val)
            {
                p->next = head;
                p = p->next;
            }
            head = head->next;
            p->next = nullptr;
        }
        return dummy->next;
    }
};
// @lc code=end

