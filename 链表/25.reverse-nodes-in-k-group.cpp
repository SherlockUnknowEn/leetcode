/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     ListNode* pre = new ListNode();
    //     pre->next = head;
    //     ListNode* cur = head;
    //     ListNode* r = head;
    //     int i = 0;
    //     for (i = 0; i < k; i++)
    //     {
    //         if (cur != nullptr)
    //             cur = cur->next;
    //         else
    //             break;            
    //     }
    //     if (i == k)
    //     {
    //         r = cur;
    //     }
    //     else
    //     {
    //         return head;
    //     }
    //     cur = head;
    //     while (true)
    //     {
    //         for (i = 0; i < k; i++)
    //         {
    //             if (cur != nullptr)
    //                 cur = cur->next;
    //             else
    //                 break;            
    //         }
    //         if (i == k)
    //         {
    //             ListNode* successor = cur->next;
    //             ListNode* start = pre->next;
    //             ListNode* last = reverse(start);
    //             start->next = successor;
    //             pre->next = last;
    //             pre = start;
    //             cur = successor;
    //         }
    //         else
    //             break;
    //     }
    //     return r;
    // }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* b = head;
        for (int i = 0; i < k; i++)
        {
            if (b != nullptr)
                b = b->next;
            else
                return head;
        }
        ListNode* p = reverseList(head, b);
        head->next = reverseKGroup(b, k);
        return p;
    }

    // 反转 left right 之间的节点
    // 左闭右开 [left, right)
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
        // 没有下面这段
        // if (right != nullptr)
        // {
        //     right->next = pre;
        //     pre = right;
        // }
        return pre;
    }
};
// @lc code=end

