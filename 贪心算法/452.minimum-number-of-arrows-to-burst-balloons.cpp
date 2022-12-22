/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int nums = 0;
        int end = INT_MIN;
        for (int i = 0; i < points.size(); i++)
        {
            if (points[i][0] > end)
            {
                end = points[i][1];
                nums++;
            }
        }
        return max(nums, 1); // [[-2147483648,2147483647]] 时会返回0
    }
};
// @lc code=end

