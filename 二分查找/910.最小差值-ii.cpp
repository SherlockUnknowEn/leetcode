/*
 * @lc app=leetcode.cn id=910 lang=cpp
 *
 * [910] 最小差值 II
 */

// @lc code=start
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int E = nums[n-1] - nums[0];
        // 从1到nums.size()的长度中任意一点都有可能是中间点
        for (int i = 1; i < n; i++) {
            int min_val = min(nums[0] + k, nums[i] - k);
            int max_val = max(nums[n-1] - k, nums[i-1] + k);
            E = min(E, max_val-min_val); 
        }
        return E;
    }
};
// @lc code=end

