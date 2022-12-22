/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(-9999);
        dummy->next = head;

        ListNode* bound = head; // 边界
        while (bound != nullptr && bound->next != nullptr)
        {
            ListNode* cur = bound->next; // 需要插入的元素
            if (bound->val <= cur->val) // 有序，不需要插入
            {
                bound = cur;
                continue;
            }
            // 找到cur其位置前一个元素
            ListNode* pre_cur = dummy;
            while (pre_cur != bound && pre_cur->next->val <= cur->val)
                pre_cur = pre_cur->next;
            bound->next = bound->next->next; // 将 cur 从链表中删除
            cur->next = pre_cur->next;
            pre_cur->next = cur;
        }
        return dummy->next;
    }
};
// @lc code=end

