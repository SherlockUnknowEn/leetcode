/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<int, vector<int>, less<int>> hp;
        vector<int> ans(k);
        // int s = INT_MAX;
        int prev = INT_MAX;
        int idx = 0;
        for (int i = 0; i < arr.size() - k + 1; i++) {
            int t = getSum(arr, i, k, x);
            if (t < prev) {
                idx = i;
            }
            else if (t > prev) {
                break; // 提前退出循环
            }
            prev = t;
        }

        for (int i = 0; i < k; i++) {
            ans[i] = arr[idx+i];
        }
        return ans;
    }

    int getSum(const vector<int>& arr, int idx, int k, int x) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += abs(arr[i+idx] - x);
        }
        return sum;
    }
};
// @lc code=end

