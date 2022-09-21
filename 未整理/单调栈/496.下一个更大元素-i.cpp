/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> table; // ni value ： 比 ni大的下一个元素是 value
        stack<int> st; // 单调栈
        vector<int> res = vector<int>(nums1.size(), -1);
        for (int i = 0; i < nums2.size(); i++)
        {
            while (!st.empty() && nums2[i] > st.top())
            {
                table[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            int n1 = nums1[i];
            if (table.find(n1) != table.end())
                res[i] = table[n1];
        }
        return res;
    }
};
// @lc code=end

