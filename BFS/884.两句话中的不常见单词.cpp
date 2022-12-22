/*
 * @lc app=leetcode.cn id=884 lang=cpp
 *
 * [884] 两句话中的不常见单词
 */

// @lc code=start
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string, int> memo;
        vector<string> words = split(s1);
        for (string& w : words) {
            cout << w << " ";
            memo[w]++;
        }
        words = split(s2);
        for (string& w : words) {
            memo[w]++;
        }
        for (auto it = memo.begin(); it != memo.end(); it++) {
            if (it->second == 1) {
                ans.push_back(it->first);
            }
        }
        return ans;
    }

    vector<string> split(const string& str) {
        string s = "";
        vector<string> ans;
        for (char c : str) {
            if (c == ' ') {
                if (s != "") {
                    ans.push_back(s);
                }
                s = "";
            } else {
                s += c;
            }
        }
        if (s != "") {
            ans.push_back(s);
        }
        return ans;
    }
};
// @lc code=end

