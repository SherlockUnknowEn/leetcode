/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        n = head;
        return valid(head);
    }

    bool valid(ListNode* head)
    {
        if (head == nullptr)
            return false;
        if (head->next != nullptr && !valid(head->next))
            return false;
        bool res = n->val == head->val;
        n = n->next;
        return res;
    }

private:
    ListNode* n;
};
// @lc code=end

