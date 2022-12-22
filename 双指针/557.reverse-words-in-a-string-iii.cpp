/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        // reverse(s, 0, s.size() - 1);
        int left = 0;
        int right = 0;
        while (left < s.size()) {
            while (right < s.size() && s[right] != ' ')
                right++;
            // cout << right << "/" << s.size() << "  ";
            reverse(s, left, right - 1);
            // cout  << "22/" << "  " << endl;
            left = right = right + 1;
        }
        return s;
    }

    void reverse(string& s, int left, int right) {
        while (left < right) {
            char c = s[left];
            s[left] = s[right];
            s[right] = c;
            left++;
            right--;
        }
    }
};
// @lc code=end

