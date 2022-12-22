/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2)
    {
        if (v1[0] == v2[0])
        {
            return v1[1] > v2[1];
        }
        return v1[0] < v2[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int start = intervals[0][0];
        int end = intervals[0][1];
        int count = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= start && intervals[i][1] <= end)
            {
                count++;
            }
            else
            {
                start = intervals[i][0];
                end = intervals[i][1];
            }            
        }
        return intervals.size() - count;
    }
};
// @lc code=end

