/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
class Solution {
public:
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     unordered_map<int, int> mapping; // nums[i] -> index
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         if (mapping.find(nums[i]) == mapping.end())
    //         {
    //             mapping.insert({ nums[i], i });
    //         }
    //     }
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         int a = nums[i];
    //         int b = target - nums[i];
    //         if (mapping.find(b) != mapping.end() && mapping[b] != i)
    //         {
    //             return { min(i+1, mapping[b]+1), max(i+1, mapping[b]+1)};
    //         }
    //     }
    //     return { };
    // }

    // vector<int> twoSum(vector<int>& nums, int target) {
    //     int left = 0;
    //     int right = nums.size() - 1;
    //     while (left < right) // 因为不能重复使用元素  因此不需要考虑 = 情况
    //     {
    //         if (nums[left] + nums[right] == target)
    //         {
    //             return { left + 1, right + 1 };
    //         }
    //         else if (nums[left] + nums[right] > target)
    //         {
    //             right = right - 1;
    //         }
    //         else if (nums[left] + nums[right] < target)
    //         {
    //             left = left + 1;
    //         }
    //     }
    //     return { };
    // }

    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] == target)
            {
                return { left + 1, right + 1 };
            }
            else if (nums[left] + nums[right] > target)
            {
                right -= 1;
            }
            else if (nums[left] + nums[right] < target)
            {
                left += 1;
            }
        }
        return { -1, -1 };
    }
};
// @lc code=end

