/*
 * @lc app=leetcode.cn id=1385 lang=cpp
 *
 * [1385] 两个数组间的距离值
 */

// @lc code=start
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int cnt = 0;
        // | a - b | <= d
        // -d <=  a - b <= d
        // a - d <= b <= a + d
        for (int a : arr1) {
            auto it1 = lower_bound(arr2.begin(), arr2.end(), a - d);
            auto it2 = upper_bound(arr2.begin(), arr2.end(), a + d);
            // cout << *it1 << " " << *it2 << endl;
            if (it1 < it2) continue;
            cnt++;
        }
        return cnt;
    }
};
// @lc code=end

