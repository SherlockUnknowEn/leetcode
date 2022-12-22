/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode less_g;
        ListNode greater_g;
        ListNode *less = &less_g;
        ListNode *greater = &greater_g;

        while (head != nullptr)
        {
            if (head->val >= x)
            {
                greater->next = head;
                greater = greater->next;
            }
            else
            {
                less->next = head;
                less = less->next;
            }
            head = head->next;
        }
        greater->next = nullptr;
        less->next = greater_g.next;
        return less_g.next; 
    }
};
// @lc code=end

