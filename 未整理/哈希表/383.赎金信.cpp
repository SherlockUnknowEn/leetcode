/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size())
            return false;
        vector<int> table(26);
        for (char c : magazine)
        {
            table[c - 'a'] += 1;
        }
        for (char c : ransomNote)
        {
            if (table[c - 'a'] <= 0)
                return false;
            table[c - 'a'] -= 1;            
        }
        return true;
    }
};
// @lc code=end

