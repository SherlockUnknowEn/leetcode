/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = n - 1;
        int y = 0;
        while (x >= 0 && y < m)
        {
            if (matrix[y][x] == target)
                return true;
            else if (matrix[y][x] < target) {
                y++;
            } else if (matrix[y][x] > target) {
                x--;
            }
        }
        return false;
    }
};
// @lc code=end

