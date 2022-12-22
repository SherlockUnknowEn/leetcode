/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for (size_t i = 0; i < (n + 1) / 2; i++) // +1 为了避免奇数时，漏处理最中间的元素
        {
            for (size_t j = 0; j < n / 2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] =  matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
};
// @lc code=end

