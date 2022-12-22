/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;
        ListNode *p1, *p2;
        p1 = p2 = head;
        while (p2->next != nullptr && p2->next->next != nullptr)
        {
            p2 = p2->next->next;
            p1 = p1->next;
            if (p2 == p1)
                return true;
        }
        return false;
    }
};
// @lc code=end

