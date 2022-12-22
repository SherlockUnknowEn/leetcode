/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // unsigned long long a = 0, b = 0;
        vector<int> a;
        vector<int> b;
        while (l1 != nullptr) {
            a.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            b.push_back(l2->val);
            l2 = l2->next;
        }

        vector<int> c;
        int jinwei = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 && j >= 0)
        {
            int val = a[i] + b[j] + jinwei;
            // cout << val << " ";
            jinwei = val / 10;
            // cout << jinwei << " ";
            c.push_back(val % 10);
            i--;
            j--;
        }
        while (i >= 0) {
            int val = a[i] + jinwei;
            jinwei = val / 10;
            c.push_back(val % 10);
            i--;
        }
        while (j >= 0) {
            int val = b[j] + jinwei;
            jinwei = val / 10;
            c.push_back(val % 10);
            j--;
        }
        if (jinwei > 0)
            c.push_back(jinwei);
        ListNode* dummy = new ListNode();
        for (int val : c) {
            ListNode* node = new ListNode(val);
            node->next = dummy->next;
            dummy->next = node;
        }
        return dummy->next;
    }
};
// @lc code=end

