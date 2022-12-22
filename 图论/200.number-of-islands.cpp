/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    floodFill(grid, i, j);
                }
            }
        }
        return res;
    }

    void floodFill(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;
        if (grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        floodFill(grid, i-1, j);
        floodFill(grid, i, j-1);
        floodFill(grid, i+1, j);
        floodFill(grid, i, j+1);
    }
};
// @lc code=end

