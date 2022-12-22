/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int val = 0;
        while (start <= end)
        {
            val = max(val, (end - start) * min(height[start], height[end]));
            if (height[start] < height[end])
                start++;
            else
                end--;
        }
        return val;        
    }
};
// @lc code=end

