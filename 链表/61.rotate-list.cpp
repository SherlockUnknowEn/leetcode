/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;       

        ListNode *p = head;
        int len = 1;
        while (p->next != nullptr) {
            len++;
            p = p->next;
        }
        k = k % len;
        if (k == 0)
            return head; // 刚好等于 length 不需要
        ListNode *d = head;
        // 找倒数第 k+1 个节点 d
        for (size_t i = 0; i < len - k - 1; i++)
        {
            d = d->next;
        }
        p->next = head;
        head = d->next;
        d->next = nullptr;
        return head;
    }
    
};
// @lc code=end

