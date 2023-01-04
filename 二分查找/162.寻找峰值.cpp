/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // mid 附近递增，峰值在右 mid附近递减，峰值在左
        if (nums.size() == 1)
            return 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) { // mid是峰顶 或 下坡
                right = mid;
            } else { // 上坡，mid并且一定不是峰顶
                left = mid + 1;
            }
        }
        return left;
    }

};
// @lc code=end

