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
    // ListNode* reverseBetween(ListNode* head, int left, int right) {
    //     ListNode* dummy = new ListNode();
    //     dummy->next = head;
    //     ListNode* n = dummy;
    //     int i = 0;
    //     while (i < left - 1)
    //     {
    //         n = n->next;
    //         i++;
    //     }
    //     ListNode* pre = n; // left 前一个节点
    //     while (i < right)
    //     {
    //         n = n->next;
    //         i++;
    //     }
    //     ListNode* last = n->next; // right后一个节点
    //     n->next = nullptr;
    //     ListNode* r = reverseList(pre->next);
    //     pre->next->next = last;
    //     pre->next = r;
    //     return dummy->next;
    // }

    // 递归解决  精炼
    // 空间复杂度高
    // ListNode* reverseBetween(ListNode* head, int left, int right) {
    //     if (left == 1)
    //         return reverseN(head, right);
    //     head->next = reverseBetween(head->next, left -1, right -1);
    //     return head;
    // }

    // ListNode* reverseN(ListNode* head, int N) {
    //     ListNode* dummy = new ListNode();
    //     dummy->next = head;
    //     ListNode* p = dummy;
    //     int i = 0;
    //     while (i < N)
    //     {
    //         p = p->next;
    //         i++;
    //     }
    //     ListNode* succ = p->next;
    //     p->next = nullptr;
    //     ListNode* last = reverseList(dummy->next);
    //     dummy->next->next = succ;
    //     return last;
    // }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* n = dummy;
        int i = 0;
        while (i < left - 1)
        {
            n = n->next;
            i++;
        }
        ListNode* pre = n; // left 前一个节点
        while (i < right)
        {
            n = n->next;
            i++;
        }
        ListNode* last = n->next; // right后一个节点
        ListNode* r = reverseList(pre->next, n);
        pre->next->next = last;
        pre->next = r;
        return dummy->next;
    }

    // 反转 left right 之间的节点
    ListNode* reverseList(ListNode* left, ListNode* right) {
        if (left == nullptr)
            return nullptr;
        if (left->next == nullptr)
            return left;
        ListNode* pre = nullptr;
        ListNode* cur = left;
        ListNode* next;
        while (cur != right)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        if (right != nullptr)
        {
            right->next = pre;
            pre = right;
        }
        return pre;
    }
};
// @lc code=end

