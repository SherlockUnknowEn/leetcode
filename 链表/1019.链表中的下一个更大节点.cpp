/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
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
    // vector<int> nextLargerNodes(ListNode* head) {
    //     vector<int> ans;
    //     ListNode* p = head;
    //     while (p !=  nullptr)
    //     {
    //         ans.push_back(p->val);
    //         p = p->next;
    //     }
    //     for (int i = 0; i < ans.size(); i++)
    //     {
    //         int t = ans[i];
    //         ans[i] = 0;
    //         for (int j = i + 1; j < ans.size(); j++)
    //         {
    //             if (ans[j] > t)
    //             {
    //                 ans[i] = ans[j];
    //                 break;
    //             }
    //         }
    //     }
    //     return ans;
    // }


    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode* p = head;
        stack<int> st; // 单调栈, 栈顶为最小元素
        while (p !=  nullptr)
        {
            ans.push_back(p->val);
            p = p->next;
        }
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            int t = ans[i];
            while (!st.empty() && st.top() <= ans[i])
                st.pop();

            if (st.empty()) {
                st.push(t);
                ans[i] = 0;
            }
            else
            {
                ans[i] = st.top();
                st.push(t);
            }
        }
        return ans;
    }
};
// @lc code=end

