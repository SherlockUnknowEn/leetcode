/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        set.insert(nums.begin(), nums.end());
        int max = 0;
        for (int x : set) {
            // 最左侧才开始查找
            if (set.find(x - 1) == set.end()) {
                int y = x + 1;
                while (set.find(y) != set.end()) {
                    y++;
                }
                max = max < (y - x) ? y - x : max;
            }
        }
        return max;
    }
};
// @lc code=end

