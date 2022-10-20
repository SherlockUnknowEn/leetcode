/*
 * @lc app=leetcode.cn id=795 lang=cpp
 *
 * [795] 区间子数组个数
 */

// @lc code=start
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int start = -1, temp = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > right)
                start = i;
            if(nums[i] >= left)
                temp = i - start;
            ans += temp;
        }
        return ans;
    }
};
// @lc code=end

