/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0)
            return 0;
        // 先对 w 升序， w相同的 h按降序排列
        sort(envelopes.begin(), envelopes.end(), cmp);
        // h 的最长递增子序列 数量即为可嵌套的信封数量
        return LIS(envelopes);
    }

    static bool cmp(vector<int>& a1, vector<int>& a2)
    {
        if (a1[0] == a2[0])
        {
            return a1[1] > a2[1];
        }
        return a1[0] < a2[0];
    }

    int LIS(const vector<vector<int>>& envelopes)
    {
        int n = envelopes.size();
        vector<int> dp(n, 1);
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (envelopes[i][1] > envelopes[j][1])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int mx = INT_MIN;
        for (size_t i = 0; i < n; i++)
        {
            mx = max(mx, dp[i]);
        }
        
        return mx;
    }
};
// @lc code=end

