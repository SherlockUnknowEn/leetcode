/*
 * @lc app=leetcode.cn id=2181 lang=cpp
 *
 * [2181] 合并零之间的节点
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        int sum = 0;
        while (head != nullptr) {
            sum += head->val;
            if (head->val == 0 && sum != 0) {
                p->next = new ListNode(sum);
                p = p->next;
                sum = 0;
            }
            head = head->next;
        }
        return dummy->next;
    }
};
// @lc code=end

