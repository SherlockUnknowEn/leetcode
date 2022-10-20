/*
 * @lc app=leetcode.cn id=1332 lang=cpp
 *
 * [1332] 删除回文子序列
 */

// @lc code=start
class Solution {
public:
    int removePalindromeSub(string s) {
        // 因为只有 'a' 'b'
        // 所以最多只需要删除 2 次， 一次删除所有的 'a'， 一次删除所有的 'b'
        if (s.size() == 0)
            return 0;
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return 2;
            }
            i++;
            j--;
        }
        return 1;
    }
};
// @lc code=end

