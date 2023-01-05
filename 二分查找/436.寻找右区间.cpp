/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1) return { -1 };
        // 1. 缓存每个区间对应的下标
        unordered_map<int, int> mm; 
        for (int i = 0; i < n; i++) {
            mm[intervals[i][0]] = i;
        }
        // 2. 对区间进行排序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[0] < b[0];
        });
        // 3. 每个区间排序后，可进行二分查找符合条件的右侧区间
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int idx = mm[intervals[i][0]]; // 区间未排序前的下标
            if (intervals[i][1] > intervals[n-1][0]) { // 如果最大的都不是右侧区间
                ans[idx] = -1;
                continue;
            }
            int right_area = biniary_search(intervals, intervals[i][1]);
            ans[idx] = mm[right_area];
        }
        return ans;
    }

    int biniary_search(const vector<vector<int>>& intervals, int target) {
        int left = 0;
        int right = intervals.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (intervals[mid][0] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return intervals[left][0];
    }

};
// @lc code=end

