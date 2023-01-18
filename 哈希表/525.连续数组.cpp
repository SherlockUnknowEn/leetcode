/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // 前缀和 + 哈希表
        // 将 0 变为 -1 
        // 1. 若前缀和为0,其长度为 i + 1
        // 2. 若前缀和nums[i] == nums[j], 则 [i+1, j]的元素 01个数相等, 长度为 j - i
        if (nums.size() < 2) {
            return 0;
        }
        int ans = 0;
        unordered_map<int, int> memo;
        nums[0] = nums[0] == 0 ? -1 : nums[0];
        memo[nums[0]] = 0;
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i] == 0 ? -1 : nums[i];
            nums[i] = nums[i] + nums[i-1];
            if (memo.find(nums[i]) == memo.end()) {
                memo[nums[i]] = i;
            } else {
                ans = max(ans, i - memo[nums[i]]);
            }
            if (nums[i] == 0) {
                ans = max(ans, i+1);
            }
        }
        
        return ans;
        // 0   0  0  1  1  0  0  1  1  1
        // -1 -2 -3 -2 -1 -2 -3 -2 -1  0
    }
};
// @lc code=end

