/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;
        char c;
        while (i < j) {
            c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
        }
    }
};
// @lc code=end

