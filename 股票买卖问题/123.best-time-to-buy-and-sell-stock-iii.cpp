/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2)));
        // base case
        dp[0][0][1] = INT_MIN;
        dp[0][1][1] = -prices[0];  // dp[i][k][0 or 1]  至第i天最多进行k次交易，手上持有或不持有股票
        dp[0][2][1] = -prices[0];
        
        for (int i = 1; i < n; i++)
        {            
            for (int j = 1; j < 3; j++)
            {
                /* code */
                // 1. 昨天没持有，今天也没持有
                // 2. 昨天持有，今天卖出
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                // 1. 昨天持有，今天继续持有
                // 2. 昨天没持有，今天买入
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
            }
        }
        return dp[n-1][2][0];
    }
};
// @lc code=end

