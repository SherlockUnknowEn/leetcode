/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string maxstr = "";
        for (size_t i = 0; i < s.length(); i++)
        {
            string a = palindrome(s, i, i);
            string b = palindrome(s, i, i+1);
            maxstr = maxstr.length() > a.length() ? maxstr : a;
            maxstr = maxstr.length() > b.length() ? maxstr : b;
        }
        return maxstr;

    }

    string palindrome(string& s, int i, int j) {
        if (i > j)
            return "";
        while (i >= 0 && j < s.length() && s[i] == s[j])
        {
            --i;
            ++j;
        }
        return s.substr(i+1, j - i - 1); 
    }
};
// @lc code=end

