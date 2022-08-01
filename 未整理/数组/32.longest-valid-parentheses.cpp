/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> dp(n);
        int maxval = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == ')')
            {
                int j = i - 1 - dp[i-1];
                if (j >= 0 && s[j] == '(')
                {
                    dp[i] = dp[i-1] + 2 + ( j-1>=0 ? dp[j-1] : 0 );
                }
            }   
        }
        for (int i = 0; i < dp.size(); i++)
        {
            maxval = max(maxval, dp[i]);
        }
        return maxval;
    }
};
// @lc code=end

