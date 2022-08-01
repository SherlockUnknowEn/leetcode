/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i-1] == nums[i])
                continue;      
            int target = 0 - nums[i];      
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target)
                {
                    res.push_back({ nums[i], nums[left], nums[right] });
                    // 去重
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left-1])
                        left++;
                    while (left < right && nums[right] == nums[right+1])
                        right--;
                }
                else if (nums[left] + nums[right] > target)
                    right--;
                else
                    left++;
            }
        }
        return res;
    }
};
// @lc code=end

