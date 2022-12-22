/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //2\n[3,3,5,0,0,3,1,4]\n    6
        int n = prices.size();
        if (k == 0 || n == 0)
        {
            return 0;
        }
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2)));
        for (int i = 0; i < n; i++)
        {
            dp[i][0][1] = INT_MIN;
        }
        for (int i = 1; i < k+1; i++)
        {
            dp[0][i][1] = -prices[0];
        }
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < k+1; j++)
            {
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
            }
        }
        return dp[n-1][k][0];
    }
};
// @lc code=end

