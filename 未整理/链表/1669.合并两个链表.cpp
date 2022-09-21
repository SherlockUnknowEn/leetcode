/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* p1 = list1;
        for (int i = 0; i < a - 1; i++) // a 的前一个节点
            p1 = p1->next;
        ListNode* pb = p1;
        for (int i = 0; i < b - a + 1; i++) // b节点
            pb = pb->next;
        ListNode* p2last = list2;
        while (p2last->next != nullptr)
            p2last = p2last->next;
        p1->next = list2;
        p2last->next =pb->next;
        return list1;
    }
};
// @lc code=end

