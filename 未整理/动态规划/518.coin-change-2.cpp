/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        // base case
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] < amount + 1)
            {
                dp[coins[j]] = 1;
            }
        }
        for (int i = 1; i < amount + 1; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] >= 0)
                {
                    dp[i] += dp[i - coins[j]];
                }
            }
        }
        
        return dp[amount];
    }
};
// @lc code=end

