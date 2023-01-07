/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        int n = s.size();
        unordered_map<char, char> map;
        unordered_set<char> memo;
        for (int i = 0; i < n; i++) {
            if (map.find(s[i]) == map.end()) {
                // 已经被映射过了
                if (memo.find(t[i]) != memo.end())
                    return false;
                map[s[i]] = t[i];
                memo.insert(t[i]);
            } else {
                if (map[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

