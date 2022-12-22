/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 1)
            return triangle[0][0];
        
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = triangle[0][0];
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                else if (j == i)
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                else
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
        
        int total = INT_MAX;
        for (int j = 0; j < n; j++) {
            total = dp[n-1][j] < total ? dp[n-1][j] : total;
        }
        return total;
    }

};
// @lc code=end

