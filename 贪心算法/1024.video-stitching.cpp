/*
 * @lc app=leetcode id=1024 lang=cpp
 *
 * [1024] Video Stitching
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        // 起点相同，选长的
        if (v1[0] == v2[0])
        {
            return v1[1] > v2[1];
        }
        return v1[0] < v2[0];
    }

    // -----------
    // ---------
    //       ------------
    //              ---------------
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), cmp);
        if (clips[0][0] != 0)
            return -1;
        int end = 0;
        int count = 0;
        int i = 0;
        while (i < clips.size() && end >= clips[i][0])
        {
            // 选择出有交集并且最长的
            int next_end = end;
            while (i < clips.size() && clips[i][0] <= end)
            {
                next_end = max(next_end, clips[i][1]);
                i++;
            }
            end = next_end;
            count++;
            if (end >= time)
            {
                return count;
            }
        }
        return -1; // 没有 time 长
    }
};
// @lc code=end

