/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string s : strs)
        {
            string s1(s);
            sort(s1.begin(), s1.end());
            m[s1].push_back(s);
        }
        for (auto iter = m.begin(); iter != m.end(); ++iter)
        {
            res.push_back(iter->second);
        }
        return res;
    }
    
    
    
    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        
        vector<vector<string>> res;
        if (strs.size() == 0)
            return res;
        res.push_back({ strs[0] });
        for (int i = 1; i < strs.size(); i++)
        {
            bool flag = true;
            for (int j = 0; j < res.size(); j++)
            {
                if(isAnagrams(res[j][0], strs[i]))
                {
                    res[j].push_back(strs[i]);
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back({ strs[i] });
        }
        return res;
    }

    bool isAnagrams(const string& s1, const string& s2)
    {
        if (s1.size() != s2.size())
            return false;
        vector<int> tb(27);
        for (char c : s1)
            tb[c - 'a']++;
        for (char c : s2)
        {
            int k = c - 'a';
            tb[k]--;
            if (tb[k] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

