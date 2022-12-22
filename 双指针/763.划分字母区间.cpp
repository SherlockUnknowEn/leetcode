/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> pos; // start end
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            pos[c] = i;
        }
        vector<int> ans;
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i <= end) {
                end = max(end, pos[s[i]]);
            } else {
                ans.push_back(end - start + 1); // 数量为下标 + 1
                start = end + 1;
                end = max(end, pos[s[i]]);
            }
        }
        ans.push_back(s.size() - start);
        return ans;
    }
};
// @lc code=end

