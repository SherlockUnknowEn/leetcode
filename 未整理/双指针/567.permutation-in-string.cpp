/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        vector<int> v1(26);
        vector<int> v2(26);
        // 滑动窗口
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            v1[s1[i] - 'a']++;
            v2[s2[i] - 'a']++;
        }
        if (v1 == v2) return true;
        for (int i = n; i < s2.size(); i++) {
            v2[s2[i - n] - 'a']--;
            v2[s2[i]  - 'a']++;
            if (v1 == v2) return true;
        }
        return false;
    }
};
// @lc code=end

