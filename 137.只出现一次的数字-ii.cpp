/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32);
        for (int a : nums) {
            for (int i = 0; i < 32; i++) {
                if (a & (1 << i))
                    bits[i]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i] % 3 != 0)
                ans |= (1 << i);
        }
        return ans;
    }
};
// @lc code=end

