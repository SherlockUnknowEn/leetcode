/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        if (n1 == 0 || n2 == 0)
            return max(n1, n2);
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));       
        // base case
        for (size_t i = 1; i < n1+1; i++)
        {
            dp[i][0] = i;
        }
        for (size_t j = 1; j < n2+1; j++)
        {
            dp[0][j] = j;
        }
        
        
        for (size_t i = 1; i <= n1; i++)
        {
            for (size_t j = 1; j <= n2; j++)
            {
                if (word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    // 增 删 改
                    // word1 -> word2
                    // 单方向，因此不需要考虑双方向的增删改
                    int ins = dp[i-1][j] + 1;
                    int del = dp[i][j-1] + 1;
                    int mod = dp[i-1][j-1] + 1;
                    dp[i][j] = min(ins, del);
                    dp[i][j] = min(dp[i][j], mod);
                }
            }
        }
        return dp[n1][n2];
    }
};
// @lc code=end

