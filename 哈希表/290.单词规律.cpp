/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map;
        unordered_set<string> hasMap;
        vector<string> words;
        split(s, words);
        if (pattern.size() != words.size())    
            return false;
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            if (map.find(c) == map.end()) {
                // a 和 b 不能同时映射到同一个单词
                if (hasMap.find(words[i]) != hasMap.end()) {
                    return false;
                }
                // cout << "c="<< c << "; wordds[i]=" << words[i] << endl;
                map[c] = words[i];
                hasMap.insert(words[i]);
            } else {
                if (map[c] != words[i]) {
                    // cout << "c="<< c << "; wordds[i]=" << words[i] << endl;
                    return false;
                }
            }
        }
        return true;
    }

    void split(const string& s, vector<string>& words) {
        string str = "";
        for (char c : s) {
            if (c == ' ') {
                words.push_back(str);
                str = "";
            } else {
                str += c;
            }
        }
        if (str != "") {
            words.push_back(str);
        }
    }
};
// @lc code=end

