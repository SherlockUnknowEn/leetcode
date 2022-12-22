/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        for (; i < nums.size() && nums[i] < 0; i++) ;
        int j = i - 1;
        vector<int> ans(n);
        for (int k = 0; k < n; k++) {
            if (i >= n) {
                ans[k] = nums[j] * nums[j];
                j--;
            } else if (j < 0) {
                ans[k] = nums[i] * nums[i];
                i++;
            } else if (abs(nums[i]) < abs(nums[j])) {
                ans[k] = nums[i] * nums[i];
                i++;
            } else {
                ans[k] = nums[j] * nums[j];
                j--;
            }
        }
        return ans;
    }
};
// @lc code=end

