/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for (int i = 0; i < columnTitle.size(); i++) {
            char c = columnTitle[i];
            ans += pow(26, columnTitle.size() - i - 1) * (c - 'A' + 1);
        }
        return ans;
    }
};
// @lc code=end

