/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *dummy = new ListNode(-999);
        
        ListNode *d = dummy;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while (p2 != nullptr) 
        {
            if (p1->val == p2->val)
            {
                // 找到下一个非重复节点
                while (p2->next != nullptr && p2->val == p1->val) {
                    p2 = p2->next;
                }
                p1 = p2;
                p2 = p2->next;
                continue;
            }
            d->next = p1;
            d = d->next;

            p1 = p1->next;
            p2 = p2->next;
        }
        // 判断最后一个是否重复节点
        if (d->val != -999 && d->val != p1->val)
        {
            d->next = p1;
            d = d->next;
            d->next = nullptr;
        }
        
        return dummy->next;
    }

};
// @lc code=end

