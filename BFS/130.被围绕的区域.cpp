/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<char>> mask(m, vector<char>(n, 'X'));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int j = 0; j < n; j++) {
            dfs(board, 0, j, mask, visited);
            dfs(board, m-1, j, mask, visited);
        }
        for (int i = 0; i < m; i++) {
            dfs(board, i, 0, mask, visited);
            dfs(board, i, n-1, mask, visited);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = mask[i][j];
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j, 
        vector<vector<char>>& mask, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return;
        if (visited[i][j])
            return;
        visited[i][j] = true;
        if (board[i][j] == 'X')
            return;
        mask[i][j] = 'O';
        dfs(board, i-1, j, mask, visited);
        dfs(board, i+1, j, mask, visited);
        dfs(board, i, j-1, mask, visited);
        dfs(board, i, j+1, mask, visited);
    }
};
// @lc code=end

