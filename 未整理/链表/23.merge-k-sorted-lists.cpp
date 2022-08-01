/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (lists.size() == 0)
            return nullptr;
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        for (int i = 0; i < n; i++)
        {
            p->next = merge2(p->next, lists[i]);
        }
        return p->next;
    }

    ListNode* merge2(ListNode* a, ListNode* b)
    {
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        while (a != nullptr && b != nullptr)
        {
            if (a->val < b->val)
            {
                p->next = a;
                p = p->next;
                a = a->next;
            }
            else
            {
                p->next = b;
                p = p->next;
                b = b->next;
            }
        }
        p->next = a == nullptr ? b : a;
        return dummy->next;
    }
};
// @lc code=end

