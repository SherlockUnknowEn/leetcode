/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int o = 0;
        for (int item : nums)
        {
            o = o ^ item;
        }
        return o;
    }
};
// @lc code=end

