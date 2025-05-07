/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel 表列名称
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while (columnNumber) {
            columnNumber--;
            ans = string(1, 'A' + columnNumber % 26) + ans;
            columnNumber = columnNumber / 26; 
        }
        return ans;
    }
};
// @lc code=end

