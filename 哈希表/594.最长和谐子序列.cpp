/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> memo; // 统计个数
        for (int i = 0; i < nums.size(); i++) {
            memo[nums[i]]++;
        }
        // 子序列只能包含 a, a+1 或 a-1, a
        for (auto& kv : memo) {
            int key = kv.first;
            // key+1 不存在于 memo时,
            // 使用 memo[key+1]这种写法会初始化 memo[key+1] = 0, 影响for循环对memo的遍历
            if (memo.find(key+1) != memo.end()) 
                ans = max(ans, memo[key] + memo[key+1]);
            if (memo.find(key-1) != memo.end())
                ans = max(ans, memo[key] + memo[key-1]);
        }
        return ans;
    }
};
// @lc code=end

