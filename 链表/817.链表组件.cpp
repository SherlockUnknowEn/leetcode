/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
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
    int numComponents(ListNode* head, vector<int>& nums) {
        // unordered_map<int, ListNode*> memo;
        // ListNode* p = head;
        // while(p != nullptr)
        // {
        //     memo[p->val] = p;
        //     p = p->next;
        // }

        // int idx = 0;
        // int ans = 0;
        // while (idx < nums.size())
        // {
        //     while (idx + 1 < nums.size() 
        //         && memo[idx]->next->val == nums[idx+1])
        //         idx++;
        //     ans++;
        //     idx++;
        // }
        // return ans;
        unordered_set<int> st;
        for (int c : nums)
            st.insert(c);
        ListNode* p = head;
        int ans = 0;
        while(p != nullptr)
        {
            if (st.find(p->val) != st.end() 
                && (p->next == nullptr || st.find(p->next->val) == st.end())) // 当前节点在，后节点不在，即为一个组件的尾部 ans+1
            {
                ans++;
            }
            p = p->next;
        }
        return ans;
    }
};
// @lc code=end

