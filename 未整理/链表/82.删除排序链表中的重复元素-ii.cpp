/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
        if (head == nullptr) return nullptr;
        ListNode* dmy = new ListNode(); 
        ListNode* d = dmy; 
        ListNode* p = head;
        ListNode* n = head->next;
        while (p != nullptr) {
            if (n == nullptr || p->val != n->val) {
                // cout << " ." << p->val;
                d->next = p;
                d = p;
                p = p->next;
            }
            else {
                int val = p->val;
                while (p != nullptr && p->val == val) {
                    // cout << " #" << p->val;
                    p = p->next;
                }
            }
            n = (p == nullptr ? p : p->next);
        }
        d->next = nullptr; // 链表结束
        return dmy->next;
    }
};
// @lc code=end

