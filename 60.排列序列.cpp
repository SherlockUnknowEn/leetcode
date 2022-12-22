/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> dict = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        return getPermutation(dict, 0, n-1, k);
    }

private:
    string getPermutation(const vector<char>& dict, int left, int right, int k)
    {
        long num = 1;
        for (int i = 1; i <= right - left + 1; i++)
            num *= i;
        long idx = k / num;
        long yu = k % num;
        return dict[idx] + "";
    }
};
// @lc code=end

