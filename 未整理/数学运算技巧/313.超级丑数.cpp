/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

// @lc code=start
class Solution {
public:
    

    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long> ugly(n);
        vector<long> product(primes.size(), 1);
        vector<long> p(primes.size(), 0);
        for (size_t i = 0; i < n; i++)
        {
            ugly[i] = *min_element(product.begin(), product.end());
            for (size_t j = 0; j < primes.size(); j++)
            {
                int point = p[j];
                if (ugly[i] >= product[j])
                {
                    product[j] = ugly[point] * primes[j];
                    p[j] = p[j] + 1;
                }
            }
        }
        
        return ugly[n-1];
    }
};
// @lc code=end

