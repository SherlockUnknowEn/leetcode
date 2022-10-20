/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        int sq = (int)sqrt(c);
        long a = 0;
        long b = sq;
        while (a <= b) {
            if (a * a + b * b < c) {
                a++;
            } else if (a * a + b * b > c) {
                b--;
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

