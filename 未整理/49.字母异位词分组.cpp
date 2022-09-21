/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(int i = 0; i < strs.size(); i++)
        {
            string s(strs[i]);
            sort(s.begin(), s.end());
            m[s].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto iter = m.begin(); iter != m.end(); ++iter)
        {
            ans.push_back(iter->second);
        }
        return ans;
    }
};
// @lc code=end

