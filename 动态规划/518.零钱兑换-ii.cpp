/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1);
        // base case
        dp[0] = 1;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = coins[i]; j < amount + 1; j++)
            {
                // 不放入 dp[j] 为自身，不改变组合数
                // 放入则 加上 j-coins[i] 的组合数
                dp[j] += dp[j-coins[i]];
            }
        }
                
        return dp[amount];
    }
};
// @lc code=end

