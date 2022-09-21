/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        sort(dictionary.begin(), dictionary.end(), [](string& s1, string& s2) -> bool { 
            if (s1.size() == s2.size()) {
                return s1 < s2;
            }
            return s1.size() > s2.size();
         });
        for (string& d : dictionary) {
            if (isSubseq(s, d)) {
                return d;
            }
        }
        return "";
    }
 

    bool isSubseq(const string& src, const string& sub) {
        int i = 0;
        int j = 0;
        while (i < src.size() && j < sub.size()) {
            if (src[i] == sub[j])
                j++;
            i++;
        }
        return j >= sub.size();
    }
};
// @lc code=end

