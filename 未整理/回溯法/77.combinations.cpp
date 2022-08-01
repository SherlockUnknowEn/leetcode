/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k <= 0 || n <= 0) return res;
        vector<int> track;
        comb(n, k, 1, track);
        return res;
    }

    void comb(int n, int k, int left, vector<int>& sub)
    {
        if (sub.size() >= k)
        {
            res.push_back(sub);
            return;
        }
        for (int i = left; i < n+1; i++)
        {
            sub.push_back(i);
            comb(n, k, i + 1, sub);
            sub.pop_back();
        }
    }
private:
    vector<vector<int>> res;
};
// @lc code=end

