/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 滑动窗口
        int ans = INT_MAX;
        int i = 0;
        int j = 0;
        int sum = 0;
        while (j < nums.size()) {
            sum += nums[j];
            ++j;
            while (sum >= target)
            {
                ans = min(ans, j - i);
                sum -= nums[i];
                i++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end

