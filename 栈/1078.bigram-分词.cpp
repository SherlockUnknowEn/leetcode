/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 */

// @lc code=start
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words = split(text, ' ');
        vector<string> ans;

        for (int i = 0; i < words.size() - 2; i++) {
            if (words[i] == first && words[i+1] == second) {
                ans.push_back(words[i+2]);
            }
        }
        return ans;
    }

    vector<string> split(const string& text, char sp) {
        vector<string> ans;
        string a = "";
        for (char c : text) {
            if (c == sp) {
                if (a != "")
                    ans.push_back(a);
                a = "";
                continue;
            } else {
                a = a + c;
            }
        }
        if (a != "")
            ans.push_back(a);
        return ans;
    }
};
// @lc code=end

