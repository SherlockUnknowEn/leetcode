/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for (int i = 0; i < n; i++) {
            int n = image[i].size();
            int left = 0;
            int right = n - 1;
            while (left <= right) {
                int t = image[i][left];
                image[i][left] = !image[i][right];
                image[i][right] = !t;
                left++;
                right--;
            } 
        }
        return image;
    }
};
// @lc code=end

