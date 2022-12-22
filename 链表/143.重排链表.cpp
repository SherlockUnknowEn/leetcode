/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode* mid = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            mid = mid->next;
            fast = fast->next->next;
        }
        ListNode* nh = reverse(mid->next);
        mid->next = nullptr;
        combine(head, nh);
    }

    ListNode* combine(ListNode* p1, ListNode* p2)
    {
        ListNode* dmy = new ListNode();
        ListNode* head = dmy;
        while (p1 != nullptr && p2 != nullptr)
        {
            dmy->next = p1;
            dmy = p1;
            p1 = p1->next;
            dmy->next = p2;
            dmy = p2;
            p2 = p2->next;
        }
        dmy->next = p1 == nullptr ? p2 : p1;
        return head->next;
    }

    ListNode* reverse(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* n = head->next;
        ListNode* h = head;
        while (n != nullptr)
        {
            ListNode* t = n->next;
            n->next = head;
            head = n;
            n = t;
        }
        h->next = nullptr;
        return head;
    }   
};
// @lc code=end

