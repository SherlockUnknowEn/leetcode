/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int an = a.length();
        int bn = b.length();
        int n = an > bn ? an : bn;
        string res = "";
        int carry = 0;
        for (int i = 0; i < n; i++) {
            int v1 = i >= an ? 0 : stoi(a[an - 1 - i]);
            int v2 = i >= bn ? 0 : stoi(b[bn - 1 - i]);
            int r = v1 + v2 + carry;
            res = char(r % 2 + '0') + res; // r 为0 2 =>'0'  1 3 => '1'
            carry = (r >= 2 ? 1 : 0);
        }
        if (carry == 1) 
            res = '1' + res;
        return res;
    }

    int stoi(char s) {
        return s - '0';
    }
};
// @lc code=end

