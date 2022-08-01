/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));

        // 如果其中一个为空串，另一个需要全删
        // base case
        for (size_t i = 1; i < n1; i++)
        {
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }
        for (size_t i = 1; i < n2; i++)
        {
            dp[0][i] = dp[0][i-1] + s2[i-1];
        }

        for (size_t i = 1; i < n1+1; i++)
        {
            for (size_t j = 1; j < n2+1; j++)
            {
                if (s1[i-1] == s2[j-1]) // 相等不需要删
                    dp[i][j] = dp[i-1][j-1];
                else 
                    // ? 不相等  选择小的那个删除
                    dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
            }
        }
        return dp[n1][n2];
    }
};
// @lc code=end

