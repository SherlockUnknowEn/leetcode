/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        int pre1 = 0;
        int pre2 = 1;
        int sum = 0;
        for (size_t i = 0; i < n-1; i++)
        {
            sum = pre1 + pre2;
            pre1 = pre2;
            pre2 = sum;
        }
        return sum;

    }
};
// @lc code=end

