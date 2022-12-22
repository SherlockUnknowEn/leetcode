/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min = prices[0];
        int max = prices[0];
        int sum = 0;
        // 滑动窗口/双指针
        for (int i = 0; i < n; i++)
        {
            if (prices[i] < min)
            {
                min = max = prices[i];
            }
            if (prices[i] > max)
            {
                max = prices[i];
                int p = max - min;
                sum = p > sum ? p : sum;
            }
        }
        return sum;
    }
};
// @lc code=end

