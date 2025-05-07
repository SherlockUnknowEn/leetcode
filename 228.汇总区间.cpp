/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i = 0;
        int n = nums.size();
        // 分组循环
        while (i < n) {
            int start = i;
            while (i < n-1 && nums[i] + 1 == nums[i + 1])
                i++;
            if (nums[i] == nums[start]) {
                ans.push_back(to_string(nums[i]));
            } else {
                ans.push_back(to_string(nums[start]) + string("->") + to_string(nums[i]));
            }
            i++;
        }
        return ans;
    }
};
// @lc code=end

