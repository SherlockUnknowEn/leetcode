/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

x^n = x^2 ^ n/2

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0 || x == 1 || n == 1) //  0 和 1 不需要计算
            return x;
        if (n == 0)
            return 1;
        if (n == INT_MIN) // 防止 int 最小值-2147483648转成正数后溢出
            return myPow(x, n + 1) / x;
        if (n < 0)
            return 1 / myPow(x, -n);
        if (n % 2 == 0)
            return myPow(x * x, n / 2);
        else
            return x * myPow(x, n - 1);
    }
};
// @lc code=end

