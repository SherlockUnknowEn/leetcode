/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return nums[0];
        
        return max(rob(nums, 0, n-2), rob(nums, 1, n-1));
    }

    int rob(const vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n == 1)
            return nums[start];        
        vector<int> dp(nums.size() + 2); // dp[i+2] 为 nums[i] 最多
        for (int i = start; i < end+1; i++)
        {
            dp[i+2] = max(dp[i] + nums[i], dp[i+1]);
        }
        return dp[end+2];
    }
};
// @lc code=end

