/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() <= 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        
        int pre = 0;
        maxSub(nums, pre, 0);
        return sum;
    }

    int maxSub(const vector<int>& nums, int pre, int cur)
    {
        if (cur > nums.size() - 1)
            return INT_MIN;
        int a = pre + nums[cur];
        int b = maxSub(nums, 0, cur + 1);
        sum = max(a, sum);
        sum = max(b, sum);
        return a;
    }
private:
    int sum = 0;
};
// @lc code=end

