/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// bool operator < (const vector<int>& v1, const vector<int>& v2) {
//     return v1[1] < v2[1];
// }



// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int nums = 0;
        int end = INT_MIN;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= end)
            {
                end = intervals[i][1];
                nums++;
            }            
        }
        return intervals.size() - nums;
    }
};

// @lc code=end

