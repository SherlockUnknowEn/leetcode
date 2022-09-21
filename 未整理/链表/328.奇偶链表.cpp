/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* p1 = odd;
        ListNode* p2 = even;
        while (odd != nullptr && even != nullptr && odd->next != nullptr && even->next != nullptr)
        {
            cout << odd->val << " " << even->val << endl;
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        // 连接在一起
        odd->next = p2;
        return p1;
    }
};
// @lc code=end

