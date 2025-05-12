/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max = INT_MIN;
        int product = 1;
        // 区间一定出现在最左或者最右
        // 两边有 1. 两正或者两负, 可以扩大区间
        //       2. 一正一负, 也能扩大一边的区间
        for (int i = 0; i < n; i++) {
            product *= nums[i];
            max = product > max ? product : max;
            if (product == 0)
                product = 1;
        }
        product = 1;
        for (int i = n - 1; i >= 0; i--) {
            product *= nums[i];
            max = product > max ? product : max;
            if (product == 0)
                product = 1;
        }
        return max;
    }
};
// @lc code=end

