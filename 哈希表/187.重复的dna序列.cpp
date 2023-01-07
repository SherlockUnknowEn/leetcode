/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) return { };
        unordered_set<string> memo;
        unordered_set<string> res;
        vector<string> ans;
        for (int i = 0; i < s.size() - 9; i++) {
            string a = s.substr(i, 10);
            if (memo.find(a) != memo.end()) {
                res.insert(a);
            }
            memo.insert(a);
        }

        for (auto& item : res) {
            ans.push_back(item);
        }
        return ans;
    }
};
// @lc code=end

