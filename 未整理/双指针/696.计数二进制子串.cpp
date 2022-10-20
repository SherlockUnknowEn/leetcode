/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        int last = 0;
        int cur = 1;
        int ans = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i-1] == s[i]) 
                cur++;
            else {
                last = cur;
                cur = 1;
            }
            if (last >= cur)
                ans++;
        }
        return ans;
    }

    int countBinarySubstrings2(string s) {
        int n = s.size();
        int ans = 0;
        int i = 0;
        while (i < n) {
            int idx = i;
            int count = 0;
            char c = s[idx];
            while (idx < n && s[idx] == c) {
                count++;
                idx++;
            }
            if (check(s, i, count))
            {
                ans += count;
                i += count; 
            }
            else
                i++;
        }
        return ans;
    }

    bool check(const string& s, int left, int len) {
        int right = left + len;
        if (right + len - 1 >= s.size())
            return false;
        for (int i = 0; i < len; i++) {
            if (s[left + i] == s[right + i])
                return false;
        }
        return true;
    }
};
// @lc code=end

