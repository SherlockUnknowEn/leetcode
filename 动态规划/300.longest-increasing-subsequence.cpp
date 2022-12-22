/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1); // 自身是子序列，初始化为 1
        // 最长递增子序列 i 为结尾时，i一定是子序列最大的元素
        for (size_t i = 0; i < nums.size(); i++)
        {
            // 在 0 到 i-1 中找到元素比 nums[i]小的，且最长的子序列
            for (size_t j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int m = 0;
        for (size_t i = 0; i < dp.size(); i++)
        {
            m = max(m, dp[i]);
        }
        return m;
    }

    // 未通过
    // int sub(const vector<int>& nums, int pre, int left, int right) {
    //     // 如果子序列是非递增  返回-1
    //     if (left >= nums.size())
    //         return 0;
        
    //     int res = -1;
    //     for (size_t i = left; i < right + 1; i++)
    //     {
    //         if (nums[i] <= pre)
    //             continue;
    //         int a = 1 + sub(nums, nums[i], i+1, right); // nums[i] 为子序列的一部分时
    //         res = max(res, a);
    //     }
    //     return res;
    // }
};
// @lc code=end