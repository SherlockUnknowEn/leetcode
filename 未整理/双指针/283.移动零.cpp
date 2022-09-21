/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (auto c : nums) {
            if (c != 0)
                nums[idx++] = c;
        }
        for (;idx < nums.size(); idx++)
            nums[idx] = 0;
    }
};
// @lc code=end

