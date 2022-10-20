/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 */

// @lc code=start
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_set<int> memo;
        unordered_set<int> ans;
        for (auto c : nums) {
            if (memo.find(c - k) != memo.end())
                ans.insert(c);
            if (memo.find(c + k) != memo.end())
                ans.insert(c);
            memo.insert(c);
        }
        return ans.size();
    }
};
// @lc code=end

