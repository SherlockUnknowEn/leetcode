/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> ss;
        for (auto c: s)
        {
            if (c >= 'a' && c <= 'z' || c >= '0' && c <= '9')
                ss.push_back(c);
            else if (c >= 'A' && c <= 'Z')
                ss.push_back('a' + c - 'A');
        }
        int i = 0;
        int j = ss.size() - 1;
        while (i < j)
        {
            // cout << ss[i] << " " << ss[j];
            if (ss[i++] != ss[j--])
                return false;
        }
        return true;
    }
};
// @lc code=end

