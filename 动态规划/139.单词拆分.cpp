/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    /**
    void replace(string& s, string& word) {
        while (s.find(word) != string::npos) {
            s.erase(s.find(word), word.size());
        }
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto word : wordDict) {
            replace(s, word);
            if (s == "") {
                return true;
            }
        }
        return false;
    }
    */

    bool recursive(string s, vector<string>& wordDict, string now) {
        if (now == s) {
            return true;
        }
        if (now.size() > s.size()) {
            return false;
        }
        for (auto& word : wordDict) {
            if (recursive(s, wordDict, now + word)) {
                return true;
            }
        }
        return false;
    }

    /**暴力回溯法
    bool wordBreak(string s, vector<string>& wordDict) {
        return recursive(s, wordDict, "");
    }
    */

    /**动态规划*/
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        set.insert(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && set.find(s.substr(j, i - j)) != set.end()) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }

};
// @lc code=end
