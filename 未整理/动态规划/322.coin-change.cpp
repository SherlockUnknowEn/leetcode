/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        // 假设已经知道面值 n 最少需要 dp[n] 枚, 由此计算 n+1 面值需要多少枚
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] < 0) // 当前为 i 面值
                    continue;
                
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
            
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }

    // int coinChange(vector<int>& coins, int amount) {
    //     vector<int> table(amount + 1, INT_MIN);
    //     return dpRecursion(coins, amount, table);
    // }

    int dpRecursion(vector<int>& coins, int amount, vector<int>& table)
    {
        if (amount < 0) // 不符合amount  无解
            return -1;
        
        if (amount == 0)
            return 0;

        if (table[amount] != INT_MIN)
            return table[amount];

        int res = INT_MAX;    
        for (size_t i = 0; i < coins.size(); i++)
        {
            int sub = dpRecursion(coins, amount - coins[i], table);
            if (sub != -1)
                res = min(1 + sub, res);
        }
        table[amount] = res == INT_MAX ? -1 : res;
        return table[amount];
    }
};
// @lc code=end

