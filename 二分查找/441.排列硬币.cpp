/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1;
        int right = n;
        int ans = 0;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (sum(mid) > n) {
                right = mid - 1;
            } else if (sum(mid) < n) {
                ans = mid;
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return ans;
    }

    long sum(long n) {
        // 等差数列求和公式
        // Sn=n(a1+an)/2
        return (1 + n) * n / 2;
    }
};
// @lc code=end

