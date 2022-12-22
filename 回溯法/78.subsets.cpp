/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> a;
        backtrack(nums, 0, a);
        return res;
    }


    void backtrack(const vector<int>& nums, int start, vector<int>& subset)
    {
        res.push_back(subset); // push_back 的时候调用拷贝构造函数  存的是副本
        for (size_t i = start; i < nums.size(); i++)
        {
            subset.push_back(nums[i]);
            backtrack(nums, i + 1, subset);
            subset.pop_back();
        }
    }
private:
    vector<vector<int>> res;
};
// @lc code=end

  