/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int up = 1, down = 1;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] > 0)
                up = down + 1;
            if (nums[i] - nums[i-1] < 0)
                down = up + 1;
        }   
        return max(up, down);
    }
};
// @lc code=end

