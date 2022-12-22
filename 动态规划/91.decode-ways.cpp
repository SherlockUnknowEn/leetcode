/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n <= 0)
            return 0;        
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        
        // dp表   以 i 为结尾能被解码的数量
        for (size_t i = 1; i < n; i++)
        {
            dp[i+1] = s[i] == '0' ? 0 : dp[i]; // 当前数字不为0，至少保证dp[i]种
            if (s[i-1] == '1' || s[i-1] == '2' && s[i] < '7')
            {
                dp[i+1] += dp[i-1];
            }
        }
        return dp[n];
    }
};
// @lc code=end

