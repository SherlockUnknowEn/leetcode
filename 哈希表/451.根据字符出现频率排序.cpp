/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        vector<int> counting(256);
        for (char c : s) {
            counting[c]++;
        }
        string ans;
        while (ans.size() < s.size()) {
            int max_idx = 0;
            for (size_t i = 0; i < counting.size(); i++) {
                if (counting[i] > counting[max_idx]) {
                    max_idx = i;
                }
            }
            ans += string(counting[max_idx], max_idx);
            counting[max_idx] = 0;
        }
        return ans;
    }
};
// @lc code=end

