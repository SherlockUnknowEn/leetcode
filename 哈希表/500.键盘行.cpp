/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */

// @lc code=start
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<unordered_set<char>> ss(3);
        vector<string> tmp = { "qwertyuiop", "asdfghjkl", "zxcvbnm" };
        for (size_t i = 0; i < tmp.size(); i++) {
            for (char c : tmp[i]) {
                ss[i].insert(c);
                ss[i].insert(c & '_'); // 转成大写
            }
        }
        vector<string> ans;
        for (const string& w : words) {
            int idx = -1;
            for (size_t i = 0; i < ss.size(); i++) {
                if (ss[i].find(w[0]) != ss[i].end()) {
                    idx = i;
                    break;
                }
            }
            bool flag = true;
            for (size_t j = 1; j < w.size(); j++) {
                if (ss[idx].find(w[j]) == ss[idx].end()) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans.push_back(w);
            }
        }
        return ans;
    }
};
// @lc code=end

