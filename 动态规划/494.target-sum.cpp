/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return find(nums, target, 0);
    }

    int find(const vector<int>& nums, int target, int cur) {
        if (cur == nums.size() - 1)
        {
            if (nums[cur] == 0 && target == 0)
                return 2; // 0 前面正负皆可
            
            if (nums[cur] == target || 0 - nums[cur] == target)
                return 1;
            return 0;
        }

        int pos = find(nums, target - nums[cur], cur + 1);
        int nag = find(nums, target + nums[cur], cur + 1);
        return pos + nag;
    }
};
// @lc code=end

