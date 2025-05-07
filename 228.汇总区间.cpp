/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        if (nums.size() == 1) return { to_string(nums[0]) };
        vector<string> ans;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if ((long)nums[i] - nums[i - 1] != 1) {
                if (prev != nums[i - 1])
                    ans.push_back(to_string(prev) + string("->") + to_string(nums[i - 1]));
                else
                    ans.push_back(to_string(prev));
                prev = nums[i];
            }
        }
        int last = nums[nums.size() - 1];
        if (prev != last) {
            ans.push_back(to_string(prev) + string("->") + to_string(last));
        } else {
            ans.push_back(to_string(last));
        }
        return ans;
    }
};
// @lc code=end

