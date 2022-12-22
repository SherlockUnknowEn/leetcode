/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1)
            return 0;
        vector<vector<int>> dp(n, vector<int>(3)); // 0 未持有  1 持有  2 冷静期
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][2] - prices[i]);
            dp[i][2] = dp[i-1][0]; // 冷静期是前一天未持有状态下的收益
        }
        return dp[n-1][0];
    }
};
// @lc code=end

