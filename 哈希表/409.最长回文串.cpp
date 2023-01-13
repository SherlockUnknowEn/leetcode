/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        // 双数一定能构造
        // 只能有一个单数
        int odd = 0;
        int ans = 0;
        unordered_map<char, int> memo;
        for (char c: s) {
            memo[c]++;
        }
        for (auto& kv : memo) {
            if (kv.second % 2 == 0) {
                ans += kv.second;
            } else {
                odd = 1;
                ans += kv.second - 1;
            }
        }
        return ans + odd;
    }
};
// @lc code=end

