/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     vector<int> dp(nums.size()); // 以 i 结尾的最大子数组和
    //     dp[0] = nums[0];
    //     for (size_t i = 1; i < nums.size(); i++)
    //     {
    //         // 要么和 i-1 相连，要么不相连
    //         dp[i] = max(nums[i], dp[i-1] + nums[i]);
            
    //     }
    //     int mn = INT_MIN;
    //     for (size_t i = 0; i < dp.size(); i++)
    //     {
    //         mn = max(mn, dp[i]);
    //     }
    //     return mn;
    // }

    int maxSubArray(vector<int>& nums) {
        if (nums.size() < 0)
            return 0;
        // 优化空间复杂度
        int dp0 = nums[0];
        int dp1 = 0;
        int m = nums[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            // 要么和 i-1 相连，要么不相连
            dp1 = max(nums[i], nums[i] + dp0);
            // dp[i] = max(nums[i], dp[i-1] + nums[i]);
            dp0 = dp1;
            m = max(m, dp1);
        }
        return m;
    }
};
// @lc code=end

