/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 */

// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // 1 3 2 ==> i j k
        int n = nums.size();
        if (n < 3) return false;
        stack<int> st;
        st.push(nums[n-1]);
        int k = INT_MIN; 
        // k 是单调栈弹出元素过程中的最大值
        // j 为栈顶元素
        // 在弹出的元素中 寻找 j 和 k
        // 单调递减栈，弹出元素一定比栈顶元素小，即保证 j > k
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] < k)
                return true;

            while (!st.empty() && nums[i] > st.top()) {
                k = max(st.top(), k);
                st.pop();
            }
            st.push(nums[i]);
        }
        // 3 1 4 1 2
        return false;
    }
};
// @lc code=end

