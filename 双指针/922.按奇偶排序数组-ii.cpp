/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        // 空间复杂度 O(1)
        int n = nums.size();
        int odd = 1;
        int even = 0;
        while (even < n) {
            if (nums[even] % 2 == 1) {
                while (nums[odd] % 2 == 1) {
                    odd += 2;
                }
                int t = nums[even];
                nums[even] = nums[odd];
                nums[odd] = t;
                odd += 2;
            }
            even += 2;
        }
        return nums;
    }
};
// @lc code=end

