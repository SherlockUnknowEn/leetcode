/*
 * @lc app=leetcode.cn id=999 lang=cpp
 *
 * [999] 可以被一步捕获的棋子数
 */

// @lc code=start
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    return dfs(board, i, j);
                }
            }
        }
        return 0;
    }

    int dfs(vector<vector<char>>& board, int i, int j) {
        int count = 0;
        vector<int> dx = { 0, 0, -1, 1 };
        vector<int> dy = { -1, 1, 0, 0 };
        for (int k = 0; k < 4; k++)
        {
            int x = j;
            int y = i;
            while (x >= 0 && x < 8 && y >= 0 && y < 8 && board[y][x] != 'B')
            {
                if (board[y][x] == 'p') {
                    count++;
                    break;
                }
                x += dx[k];
                y += dy[k];
            }
        }
        return count;
    }
};
// @lc code=end

