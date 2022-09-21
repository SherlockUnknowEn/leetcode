/*
 * @lc app=leetcode.cn id=1201 lang=cpp
 *
 * [1201] 丑数 III
 */

// @lc code=start
class Solution {
public:
    // 单调函数，[1, ... , num] 中能被 a b c 整除的元素个数
    int f(int num, int a, int b, int c)
    {

    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        
    }

    int nthUglyNumber2(int n, int a, int b, int c) {
        vector<long> ugly(n);
        long product_a = a, product_b = b, product_c = c;
        for (size_t i = 0; i < n; i++)
        {
            ugly[i] = min(min(product_a, product_b), product_c);

            while (ugly[i] >= product_a)
            {
                product_a += a;
            }
            while (ugly[i] >= product_b)
            {
                product_b += b;
            }
            while (ugly[i] >= product_c)
            {
                product_c += c;
            }
        }
        return ugly[n-1];
    }
};
// @lc code=end

