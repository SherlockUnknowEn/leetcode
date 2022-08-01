#
# @lc app=leetcode id=91 lang=python3
#
# [91] Decode Ways
#

# @lc code=start
class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = int[n+1]
        dp[0] = 1
        dp[1] = 0 if s[0] == '0' else 1
        for i in range(1, n+1):
            pass
        return dp[n]
# @lc code=end

