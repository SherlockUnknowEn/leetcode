/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> table(26); // 只有小写字母
        for (int i = 0; i < s.size(); i++)
        {
            table[s[i] - 'a'] += 1;
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (table[t[i] - 'a'] <= 0)
                return false;
            table[t[i] - 'a'] -= 1;
        }
        
        return true;
    }
};
// @lc code=end

