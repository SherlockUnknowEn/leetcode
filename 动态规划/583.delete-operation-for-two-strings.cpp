/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        // 求 word1 和 word2 的最长公共子序列 长度 ln
        // word1.length + word2.length - 2 * ln 即为结果
        int ln = LCS(word1, word2);
        return word1.length() + word2.length() - 2 * ln;
    }

    int LCS(const string& word1, const string& word2)
    {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));
        for (size_t i = 1; i < n1+1; i++)
        {
            for (size_t j = 1; j < n2+1; j++)
            {
                if (word1[i-1] == word2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n1][n2];
    }
};
// @lc code=end

