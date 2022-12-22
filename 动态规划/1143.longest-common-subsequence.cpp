/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        if (n1 == 0 || n2 == 0)
            return 0;
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));        
        for (size_t i = 1; i < n1+1; i++) // 为了避免 i-1  j-1 小于0   从1开始遍历
        {
            for (size_t j = 1; j < n2+1; j++)
            {
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);                   
            }
        }
        return dp[n1][n2];
    }

    // int longestCommonSubsequence(string text1, string text2) {
    //     map.clear();
    //     int n1 = text1.length();
    //     int n2 = text2.length();
    //     return sub(text1, n1 - 1, text2, n2 - 1);
    // }

    // // 递归的方法  时间复杂度太高
    // int sub(string& text1, int r1, string& text2, int r2)
    // {
    //     if (r1 < 0 || r2 < 0)
    //         return 0;
    //     string key = to_string(r1) + "," + to_string(r2);
    //     if (map.find(key) != map.end())
    //         return map[key];
    //     int res = -1;
    //     if (text1[r1] == text2[r2])
    //         res = 1 + sub(text1, r1 - 1, text2, r2 - 1);
    //     else
    //         res = max(sub(text1, r1 - 1, text2, r2), sub(text1, r1, text2, r2 - 1));
    //     map.insert({ to_string(r1) + "," + to_string(r2), res });
    //     return res;
    // }

// private:
//     unordered_map<string, int> map;
};
// @lc code=end

