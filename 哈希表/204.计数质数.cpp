/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);

        int ans = 0;
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i]) {
                ans++;
                // i 的倍数都不是质数
                int m = 2;
                while (m * i < n)
                {
                    isPrime[m*i] = false;
                    m++;
                }
            }       
        }
        return ans;
        
    }
};
// @lc code=end

