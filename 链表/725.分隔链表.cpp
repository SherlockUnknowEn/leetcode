/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* p = head;
        vector<ListNode*> ans(k, nullptr);
        int sz = 0;
        while (p != nullptr)
        {
            sz++;
            p = p->next;
        }
        int yu = sz % k;
        int shang = sz / k;
        vector<int> nums(k, shang);
        int idx = 0;
        for (int i = 0; i < yu; i++)
            nums[idx++] += 1;

        for (int i = 0; i < k; i++)
        {
            ans[i] = head;
            for (int j = 0; j < nums[i]; j++)
            {
                if (j == nums[i] - 1)
                {
                    ListNode* t = head->next;
                    head->next = nullptr;
                    head = t;
                }
                else
                {
                    head = head->next;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

