/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }

    bool backtrack(vector<vector<char>>& board, int row, int col)
    {
        if (row >= LEN)
        {
            return true; // 整个棋盘遍历完成
        }
        if (col >= LEN) // 换下一行
        {
            return backtrack(board, row + 1, 0);
        }
        if (board[row][col] != '.') // 有数字则不用填
        {
            return backtrack(board, row, col+1);
        }
        for (int i = 0; i < charset.size(); i++)
        {
            char ch = charset[i];
            if (!valid(board, row, col, ch))
            {
                continue;
            }
            
            // 没找到  回溯
            board[row][col] = ch;
            if (backtrack(board, row, col+1)) // 找到合适的
            {
                return true;
            }
            board[row][col] = '.';
        }
        return false;
    }

    // 对 [i, j] 位置验证是否合法
    bool valid(const vector<vector<char>>& board, int row, int col, char ch) const
    {
        for (int i = 0; i < LEN; i++)
        {
            if (i != row && ch == board[i][col])
            {
                return false;
            }
            if (i != col && ch == board[row][i])
            {
                return false;
            }
        }

        int patch_i = row / 3;
        int patch_j = col / 3;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int a = patch_i * 3 + i;
                int b = patch_j *3 + j;
                if (a != row && b != col && ch == board[a][b])
                {
                    return false;
                }
            }
        }
        return true;
    }


private:
    vector<char> charset = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int LEN = 9;
};
// @lc code=end

