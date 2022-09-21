/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        char c;
        while (i < j)
        {
            while (!isYuanyin(s[i]) && i < j)
                i++;
            while (!isYuanyin(s[j]) && i < j)
                j--;
            if (i < j)
            {
                c = s[i];
                s[i] = s[j];
                s[j] = c;
            }            
            i++;
            j--;
        }
        return s;
    }

    bool isYuanyin(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};
// @lc code=end

