/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int left = 0;
        int right = 0;
        int n = s.size();
        while (left < n) {
            right = min(n - 1, left + k - 1);
            reverse(s, left, right);
            left = left + 2 * k;
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

