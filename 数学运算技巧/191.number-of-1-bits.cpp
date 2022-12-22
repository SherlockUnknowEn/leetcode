/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while (n != 0)
        {
            sum++;
            n = n&(n-1);
        }
        return sum;
    }

    // int hammingWeight(uint32_t n) {
    //     int sum = 0;
    //     uint32_t i = 1;
    //     while (n != 0)
    //     {
    //         if (n & i == 1)
    //         {
    //             sum++;
    //         }
    //         n = n >> 1;
    //     }
    //     return sum;
    // }
};
// @lc code=end

