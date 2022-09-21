/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 0)
            return 0;
        
        unordered_map<char, int> map;
        int start = 0;
        int maxlen = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (map.find(s[i]) == map.end()) // 未有重复
                map.insert({ s[i], i });
            else
            {
                start = map[s[i]] + 1 > start ? map[s[i]] + 1 : start;
                map[s[i]] = i;
            }
            maxlen = max(maxlen, i - start + 1);
        }
        return maxlen;
    }

};
// @lc code=end

