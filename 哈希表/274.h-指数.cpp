/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int m = citations.size();
        int left = 0;
        int right = m - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= (m - mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (citations[right] == 0) return 0; // testcase: [0]
        return m - right;
    }
};
// @lc code=end

