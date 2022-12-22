/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */

// @lc code=start
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size(), s.size());
        int pos = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c)
                pos = i;
            if (pos != -1) {
                ans[i] = min(ans[i], i - pos);
            }
        }
        pos = s.size();
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == c)
                pos = i;
            if (pos != s.size()) {
                ans[i] = min(ans[i], pos - i);
            }
        }
        return ans;
    }
};
// @lc code=end

