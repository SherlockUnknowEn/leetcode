/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    // 递归法
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1)
            // 如果从表头开始反转，相当于反转前N个节点
            return reverseN(head, right);
        // 对于 head->next 相当于反转区间为 [left - 1, right - 1]
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }

    ListNode* right_plus;

    ListNode* reverseN(ListNode* head, int right) {
        if (right == 1)
        {
            right_plus = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, right - 1);
        head->next->next = head;
        // head->next = nullptr; // 全链表翻转时
        head->next = right_plus;
        return last;
    }

    // 头插法
    ListNode* reverseBetween2(ListNode* head, int left, int right) {
        ListNode *dummy;
        dummy->next = head;
        ListNode *g = dummy, *p = dummy->next;
        
        for (size_t i = 0; i < left; i++)
        {
            g = g->next;
            p = p->next;
        }
        for (size_t i = 0; i < right - left; i++)
        {
            ListNode *tmp = p->next;
            p->next = p->next->next;
            tmp->next = g->next;
            g->next = tmp;
        }
        return dummy->next;
    }
};
// @lc code=end

