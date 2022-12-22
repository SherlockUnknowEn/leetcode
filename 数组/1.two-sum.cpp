/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int val = target - nums[i];
            if (map.find(val) != map.end() && map[val] != i)
            {
                return { i, map[val] };
            }
        }
        return { -1, -1 };
    }
};
// @lc code=end

