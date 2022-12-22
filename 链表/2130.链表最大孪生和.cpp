/*
 * @lc app=leetcode.cn id=2130 lang=cpp
 *
 * [2130] 链表最大孪生和
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
    int pairSum(ListNode* head) {
        vector<int> memo;
        while (head != nullptr) {
            memo.push_back(head->val);
            head = head->next;
        }
        int maxsum = 0;
        int n = memo.size();
        for (int i = 0; i < n / 2; i++) {
            maxsum = max(maxsum, memo[i] + memo[n - 1 - i]);
        }
        return maxsum;
    }
};
// @lc code=end

