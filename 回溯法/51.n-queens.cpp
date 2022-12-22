/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> a;
        backtrack(n, a);
        return res;
    }

    void backtrack(int n, vector<string>& sub)
    {
        if (sub.size() == n)
        {
            res.push_back(sub);
        }
        for (int i = 0; i < n; i++)
        {
            string p(n, '.');
            p[i] = 'Q';
            if (!valid(n, sub, p))
            {
                continue;
            }
            sub.push_back(p);
            backtrack(n, sub);
            sub.pop_back();
        }
    }

    bool valid(int n, const vector<string>& sub, const string& p) const
    {
        for (int i = 0; i < sub.size(); i++)
        {
            if (sub[i] == p)
            {
                return false;
            }
            int x1 = p.find('Q');
            int x2 = sub[i].find('Q');
            int dis = sub.size() - i;
            if (x1 + dis == x2 || x1 - dis == x2) // 斜方向
            {
                return false;
            }
        }
        return true;
    }
private:
    vector<vector<string>> res;
};
// @lc code=end

