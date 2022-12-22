/*
 * @lc app=leetcode.cn id=1171 lang=cpp
 *
 * [1171] 从链表中删去总和值为零的连续节点
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // 前缀和跳跃
        // 前缀和相同的两个节点，其中间的节点相加为0
        unordered_map<int, ListNode*> memo;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = head;
        int presum = 0;
        while (p != nullptr)
        {
            presum = p->val + presum;
            memo[presum] = p;
            p->val = presum;
            p = p->next;
        }
        p = dummy; // 从dummy开始，因为 [1, -1] 这种情况需要全丢弃
        presum = 0;
        while (p != nullptr)
        {
            if (memo[p->val] != nullptr && memo[p->val] != p) {
                p->next = memo[p->val]->next;
            }
            int t = p->val;
            p->val = p->val - presum;
            presum = t;
            p = p->next;
        }
        return dummy->next;
    }
};
// @lc code=end

