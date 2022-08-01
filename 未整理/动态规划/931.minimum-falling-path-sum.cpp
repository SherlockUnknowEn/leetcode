/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0] = matrix[0];
        // 二维dp表， dp[i, j]处的最小值，
        // 为上一行 dp[i-1, j] 及其左右两个元素(dp[i-1, j-1] dp[i-1, j+1])处的最小值 加上 matrix[i, j]
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 特殊值使用 99999，使用INT_MAX 会有溢出风险
                int left = j-1 < 0 ? 99999 : dp[i-1][j-1];
                int top = dp[i-1][j];
                int right = j+1 >= n ? 99999 : dp[i-1][j+1];
                int mn = min(left + matrix[i][j], top + matrix[i][j]);
                mn = min(mn, right + matrix[i][j]);
                dp[i][j] = mn;
            }
        }
        
        int m = INT_MAX;
        for (size_t i = 0; i < n; i++)
        {
            m = min(m, dp[n - 1][i]);
        }
        return m;
    }
};
// @lc code=end

