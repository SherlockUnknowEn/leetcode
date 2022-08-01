/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */
// @lc code=start
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        
        track.insert(board);

        queue<vector<vector<int>>> q;
        q.push(board);
        int count = 0;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                vector<vector<int>> b = q.front();
                q.pop();

                if (succ(b))
                {
                    return count;
                }
                
                vector<int> pos = position0(b);
                // 上下左右
                up(q, b, pos[0], pos[1]);
                down(q, b, pos[0], pos[1]);
                left(q, b, pos[0], pos[1]);
                right(q, b, pos[0], pos[1]);
            }
            count++;
        }
        return -1;
    }


    bool succ(const vector<vector<int>>& board) const
    {
        return board[0][0] == 1 && board[0][1] == 2 && board[0][2] == 3 && board[1][0] == 4 && board[1][2] == 5;
    }

    void up(queue<vector<vector<int>>>& q, vector<vector<int>> board, int i, int j)
    {
        if (i - 1 < 0 || track.count(board) != 0)
        {
            return;
        }
        
        int temp = board[i][j];
        board[i][j] = board[i-1][j];
        board[i-1][j] = temp;
    }

    void down(queue<vector<vector<int>>>& q, vector<vector<int>> board, int i, int j)
    {
        if (i + 1 > 2 || track.count(board) != 0)
        {
            return;
        }
        int temp = board[i][j];
        board[i][j] = board[i+1][j];
        board[i+1][j] = temp;
    }

    void left(queue<vector<vector<int>>>& q, vector<vector<int>> board, int i, int j)
    {
        if (j - 1 < 0 || track.count(board) != 0)
        {
            return;
        }
        int temp = board[i][j];
        board[i][j] = board[i][j-1];
        board[i][j-1] = temp;
    }

    void right(queue<vector<vector<int>>>& q, vector<vector<int>> board, int i, int j)
    {
        if (j + 1 > 3 || track.count(board) != 0)
        {
            return;
        }
        int temp = board[i][j];
        board[i][j] = board[i][j+1];
        board[i][j+1] = temp;
    }


    vector<int> position0(const vector<vector<int>>& board) const
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 0)
                {
                    return { i, j };
                }
            }
        }
        return { -1, -1 };
    }

private:
    set<vector<vector<int>>> track;
};
// @lc code=end

