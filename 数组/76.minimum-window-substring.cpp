/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need; // 记录 t 的各元素个数
        unordered_map<char, int> window; // 记录窗口内 各元素个数
        for (char c : t)
        {
            need[c]++;
        }
        int left = 0;
        int right = 0; // 窗口 左闭右开
        int valid = 0;
        int len = INT_MAX;
        int start = 0;
        while (right < s.size())
        {
            // 扩大右窗口
            char c = s[right];
            right++;
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }


            // 这里是 while
            while (valid == need.size()) // 已经能覆盖
            {
                // 覆盖最小子串
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                // 收缩左窗口
                char d = s[left];
                left++;
                if (need.count(d))
                {
                     // 出去一个 a valid 减一， 再出去一个，不需要减
                     if (window[d] == need[d])
                         valid--;
                     window[d]--;
                }
            }
        }
        return len != INT_MAX ? s.substr(start, len) : "";
    }
};
// @lc code=end

