/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */

// @lc code=start
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                // 二分法搜索
                int left = j + 1;
                int right = nums.size() - 1;
                int b = j;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] < nums[i] + nums[j]) {
                        left = mid + 1;
                        b = mid;
                    } else {
                        right = mid - 1;
                    }
                }
                // cout << left << " " << right << " " << j << endl;
                ans += (b - j);
            }
        }
        return ans;
    }
    
};
// @lc code=end

