/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        vector<vector<int>> dp(n, vector<int>(2)); // dp[i][0] 第i天不持有股票的收益 dp[i][1]第i天持有股票的收益
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i-1][0], prices[i] + dp[i-1][1]); //不持有   1. 昨天也没持有且今天不买   2. 卖掉上一天的持有量
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]); // 1. 继续持有上一天的    2. 昨天未持有，今天购入
        }
        return dp[n-1][0];
    }
};
// @lc code=end

