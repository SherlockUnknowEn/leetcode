/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */

// @lc code=start
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // 统计边界的最大个数
        unordered_map<int, int> bound;
        for (const vector<int>& v : wall)
        {
            int x = 0;
            for (int i = 0; i < v.size() - 1; i++) {
                x += v[i];
                bound[x]++;
            }
        }
        int res = 0;
        for (auto& kv : bound) {
            res = max(res, kv.second);
        }
        return wall.size() - res;
    }
};
// @lc code=end

