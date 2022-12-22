/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 1; // 最小装1
        int right = 50000 * 500; // 最大装 weights.length * weights[i] 的最大值
        while (left <= right)
        {
            int cap = left + (right - left) / 2;
            if (f(weights, cap) == days)
            {
                right = cap - 1;
            }
            else if (f(weights, cap) == -1)
            {
                left = cap + 1;
            }
            else if (f(weights, cap) > days)
            {
                left = cap + 1;
            }
            else if (f(weights, cap) < days)
            {
                right = cap - 1;
            }
        }
        return left;
    }

    int f(const vector<int>& weights, int capacity) {
        int days = 0;
        for (int i = 0; i < weights.size(); )
        {
            int c = capacity;
            while (i < weights.size())
            {
                if (weights[i] > capacity)
                {
                    return -1;
                }
                
                if (c < weights[i])
                    break;
                else
                    c -= weights[i];
                i++;
            }
            days++;
        }
        
        return days;
    }
};
// @lc code=end

