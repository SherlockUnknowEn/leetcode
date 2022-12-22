/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int idx1 = 0;
        for (char c : s) {
            if (c == '#')
                idx1 = max(0, idx1 - 1);
            else 
                s[idx1++] = c;
        }
        int idx2 = 0;
        for (char c : t) {
            if (c == '#')
                idx2 = max(0, idx2 - 1);
            else 
                t[idx2++] = c;
        }
        return idx1 == idx2 && s.substr(0, idx1) == t.substr(0, idx2);
    }
};
// @lc code=end

