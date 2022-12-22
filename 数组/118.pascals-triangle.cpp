/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1)
        {
            vector<vector<int>> a = {{1}};
            return a;
        }

        vector<vector<int>> res = {{1}, {1, 1}};
        for (int i = 2; i < numRows; i++)
        {
            vector<int> a;
            a.push_back(1);
            for (int j = 0; j < res[i-1].size() - 1; j++)
            {
                int m = res[i-1][j] + res[i-1][j+1];
                a.push_back(m);
            }
            a.push_back(1);
            res.push_back(a);
        }
        return res;
    }
};
// @lc code=end


