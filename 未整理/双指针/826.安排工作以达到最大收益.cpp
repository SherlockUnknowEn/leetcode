/*
 * @lc app=leetcode.cn id=826 lang=cpp
 *
 * [826] 安排工作以达到最大收益
 */

// @lc code=start
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<vector<int>> diffi_profit;
        int n = difficulty.size();
        for (int i = 0; i < n; i++) {
            diffi_profit.push_back({ difficulty[i], profit[i] });
        }
        sort(diffi_profit.begin(), diffi_profit.end(), Solution::func);
        vector<int> value_vec(n);
        int maxval = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxval = max(maxval, diffi_profit[i][1]);
            value_vec[i] = maxval;
        }
        int ans = 0;
        for (int i = 0; i < worker.size(); i++) {
            int pos = bsearch(diffi_profit, 0, diffi_profit.size() - 1, worker[i]);
            if (pos < 0)
                continue;
            ans += value_vec[pos];
        }
        return ans;
    }

    int bsearch(const vector<vector<int>>& v, int left, int right, int target) {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (v[mid][0] > target)
                right = mid - 1;
            else if (v[mid][0] < target)
                left = mid + 1;
            else if (v[mid][0] == target)
                left = mid + 1;
        }
        return right;
    }

    static bool func(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
};
// @lc code=end

