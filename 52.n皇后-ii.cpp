/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        vector<int> visited(n, false);
        vector<int> pos;
        traceback(n, 0, pos, visited);
        return res.size();
    }

    void traceback(int n, int idx, vector<int>& pos, vector<int>& visited)
    {
        if (idx >= n)
        {
            res.push_back(pos);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;
            if (attack(pos, i, idx))
                continue;
            pos.push_back(i);
            visited[i] = true;
            traceback(n, idx + 1, pos, visited);
            pos.pop_back();
            visited[i] = false;
        }
    }
    
    bool attack(const vector<int>& pos, int x, int y)
    {
        for (int j = 0; j < pos.size(); j++)
        {
            if (abs(y - j) == abs(x - pos[j]))
                return true;
        }
        return false;
    }
private:
    vector<vector<int>> res;
};
// @lc code=end

