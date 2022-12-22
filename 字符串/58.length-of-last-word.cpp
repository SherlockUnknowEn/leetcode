/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        while (i >= 0 && s[i] == ' ')  // 从末尾找第一个非空格
            i--;
        if (i < 0) return s.length();
        int n1 = i;
        while (i >= 0 && s[i] != ' ') // 找到单词前一个空格
            i--;
        int n2 = i;
        return n1 - n2;                   
    }
};
// @lc code=end

