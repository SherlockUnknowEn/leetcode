/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        
        vector<string> zig(numRows, "");
        int r = 0;
        bool down = true;
        for (int i = 0; i < s.length(); i++) {
            zig[r] += s[i];
            if (r == 0) {
                down = true; 
            }
            else if (r == numRows - 1) {
                down = false;
            }
            r = down ? r + 1 : r - 1;
        }
        string res = "";
        for (int i = 0; i < zig.size(); i++) {
            res += zig[i];
        }
        return res;
    }
};
// @lc code=end

