/*
 * @lc app=leetcode.cn id=1030 lang=cpp
 *
 * [1030] 距离顺序排列矩阵单元格
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<vector<int>>> cup(200);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int a = abs(i - rCenter);
                int b = abs(j - cCenter);
                int dis = a + b;
                cup[dis].push_back({ i, j });
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < cup.size(); i++) {
            for (int j = 0; j < cup[i].size(); j++) {
                ans.push_back(cup[i][j]);
            }
        }
        return ans;

    }
};
// @lc code=end

