/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> memo(255);
        for (char c : s) {
            memo[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (memo[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

