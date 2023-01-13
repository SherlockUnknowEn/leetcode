/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};
        int k = p.size();
        vector<int> mp(256);
        vector<int> ms(256);
        for (int i = 0; i < k; i++) {
            mp[p[i]]++;
            ms[s[i]]++;
        }
        vector<int> ans;
        if (mp == ms) ans.push_back(0);
        // 滑动窗口
        for (int i = k; i < s.size(); i++) {
            // 丢弃一个
            ms[s[i-k]]--;
            // 加入一个
            ms[s[i]]++;
            if (mp == ms) ans.push_back(i-k+1); 
        }
        return ans;
    }
};
// @lc code=end

