/*
 * @lc app=leetcode.cn id=786 lang=cpp
 *
 * [786] 第 K 个最小的素数分数
 */

// @lc code=start
class Solution {
public:
    // vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    //     int n = arr.size();
    //     vector<vector<int>> vec;
    //     for (int i = 0; i < n; i++) {
    //         for (int j = i + 1; j < n; j++) {
    //             vec.push_back({ arr[i], arr[j] });
    //         }
    //     }

    //     sort(vec.begin(), vec.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
    //         return a[0] * b[1] < b[0] * a[1];
    //     });

    //     return vec[k-1];
    // }

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0.0;
        double right = 1.0;
        while (left < right) {
            double mid = left + (right - left) / 2;
            vector<int> ans = { 0, 1 };
            // mid 左边有多少个
            int count = left_count(arr, mid, ans);
            if (count == k) // mid 左边正好有 k 个，即为ans
                return ans;
            else if (count < k)
                left = mid;
            else
                right = mid;
        }
        return { 0, 1 };
    }


    int left_count(const vector<int>& arr, double mid, vector<int>& bound) {
        int count = 0;
        // 两层for循环仍可以优化
        for (int j = 1; j < arr.size(); j++) {
            for (int i = 0; i < j; i++) {
                if ((double) arr[i] / arr[j] < mid) {
                    count++;
                    if (arr[i] * bound[1] > bound[0] * arr[j]) {
                        bound[0] = arr[i];
                        bound[1] = arr[j];
                    }
                } else {
                    break;
                }
            }
        }
        return count;
    }
};
// @lc code=end

