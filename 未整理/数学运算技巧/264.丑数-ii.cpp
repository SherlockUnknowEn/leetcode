/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// 1*2 -> 2*2 -> 3*2 -> 4*2 -> 5*2 -> 6*2 -> 8*2  能被2整除的丑数
// 1*3 -> 2*3 -> 3*3 -> 4*3 -> 5*3 -> 6*3 -> 8*3  能被3整除的丑数
// 1*5 -> 2*5 -> 3*5 -> 4*5 -> 5*5 -> 6*5 -> 8*5  能被5整除的丑数
// 合并链表


// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        int product2 = 1, product3 = 1, product5 = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        vector<int> ugly(n, 0);
        for (int i = 0; i < n; i++)
        {
            ugly[i] = min(min(product2, product3), product5);
            if (ugly[i] >= product2)
            {
                product2 = ugly[p2] * 2;
                p2++;
            }
            if (ugly[i] >= product3)
            {
                product3 = ugly[p3] * 3;
                p3++;
            }
            if (ugly[i] >= product5)
            {
                product5 = ugly[p5] * 5;
                p5++;
            }
        }
        return ugly[n-1];
    }
};
// @lc code=end
