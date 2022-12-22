/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int pixel = image[sr][sc];
        if (pixel == color)
            return image;
        dfs(image, sr, sc, pixel, color);
        return image;
    }

    void dfs(vector<vector<int>>& image, int i, int j, int pixel, int color) {
        // cout << i << " " << j << endl;
        if (i < 0 || j < 0)
            return;
        if (i >= image.size() || j >= image[0].size())
            return;
        if (image[i][j] == pixel) {
            image[i][j] = color;
            dfs(image, i-1, j, pixel, color);
            dfs(image, i+1, j, pixel, color);
            dfs(image, i, j-1, pixel, color);
            dfs(image, i, j+1, pixel, color);
        }
    }
};
// @lc code=end

