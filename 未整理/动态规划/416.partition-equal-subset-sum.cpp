/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    // 回溯法  超时
    // bool canPartition(vector<int>& nums) {
    //     int pack1 = nums[0];
    //     int pack2 = 0;
    //     return traceback(nums, pack1, pack2, 1);
    // }


    // bool traceback(const vector<int>& nums, int pack1, int pack2, int i) {
    //     if (i >= nums.size())
    //         return pack1 == pack2;
    //     bool left = traceback(nums, pack1 + nums[i], pack2, i+1);
    //     if (left)
    //         return true;
    //     bool right = traceback(nums, pack1, pack2 + nums[i], i+1);
    //     if (right)
    //         return true;        
    //     return false;
    // }



    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if (sum % 2 != 0) // 不为偶数，定不可二分相同
        {
            return false;
        }
        int target = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false)); // dp[i][j] 前i个物品，
        for (int i = 0; i < n; i++)
        {
            // 背包容量为 0 说明装满
            dp[i][0] = true;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < target + 1; j++)
            {
                if (j - nums[i] < 0)
                {
                    dp[i][j] = dp[i-1][j];
                } else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i]];    
            }
        }
        return dp[n-1][target];
    }

};
// @lc code=end

