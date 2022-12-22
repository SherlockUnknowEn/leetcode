/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        if (n <= 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(n));
        // base case  每一个字符都是自身的子序列
        for (size_t i = 0; i < n; i++)
            dp[i][i] = 1;
        
        for (int i = n-1; i >= 0; i--)
        {
            for (int j = i+1; j < n; j++)
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
            
        }
        return dp[0][n-1];
    }
};
// @lc code=end

