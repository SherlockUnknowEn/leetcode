/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        return dfs(matrix, 0, matrix[0].size() - 1, visited);
    }

    bool dfs(const vector<vector<int>>& matrix, int i, int j, vector<vector<bool>>& visited) {
        if (j <= 0 || i >= matrix.size() -1)
            return true;
        if (visited[i][j])
            return true;
        if (matrix[i][j-1] != matrix[i+1][j])
            return false;
        visited[i][j] = true;
        return dfs(matrix, i, j-1, visited) && dfs(matrix, i+1, j, visited);
    }
};
// @lc code=end

