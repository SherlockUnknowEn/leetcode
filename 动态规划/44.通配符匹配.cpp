/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        // return match(s, 0, p, 0);
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < n; i++)
        {
            if (p[i] == '*')
                dp[0][i + 1] = true;
            else
                break;
        }
        
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (p[j-1] == '?')
                {
                    dp[i][j] = dp[i-1][j-1]; // 对 s[i-1] 没有要求
                }
                else if (p[j-1] == '*')
                {
                    // 对 s[i-1] 没有要求
                    bool a = dp[i][j-1]; // 通配单个或多个字符
                    bool b = dp[i-1][j]; // 通配 0 个字符
                    dp[i][j] = a || b;
                }
                else
                {
                    dp[i][j] = (s[i-1] == p[j-1]) && dp[i-1][j-1];
                }
            }
        }

        return dp[m][n];
    }

    bool match(const string& s, int i, const string& p, int j)
    {
        if (i >= s.size() && j >= p.size())
            return true;

        if (i < s.size() && j >= p.size())
            return false;
        if (i >= s.size() && j < p.size())
        {
            while (j < p.size())
            {
                if (p[j] != '*')
                    return false;
                j++;
            }
            return true;
        }
            
        if (p[j] == '?')
            return match(s, i + 1, p, j + 1);
        if (j < p.size() - 1 && p[j] == '*' && p[j+1] == '*') // 多个 * 连续，视为一个*
            return match(s, i, p, j + 1);
        if (p[j] == '*')
            return match(s, i, p, j + 1) || match(s, i + 1, p, j + 1) || match(s, i + 1, p, j);
        if (s[i] == p[j])
            return match(s, i + 1, p, j + 1);
        return false;
    }
};
// @lc code=end

