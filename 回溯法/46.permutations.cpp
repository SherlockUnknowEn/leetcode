/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> a;
        backtrack(nums, 0, a);
        return res;
    }

    void backtrack(const vector<int>& nums, int left, vector<int>& sub)
    {
        if (sub.size() == nums.size())
        {
            res.push_back(sub);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (find(sub.begin(), sub.end(), nums[i]) != sub.end())
            {
                continue;
            }
            
            sub.push_back(nums[i]);
            backtrack(nums, i + 1, sub);
            sub.pop_back();
        }
        
    }

private:
    vector<vector<int>> res;
};
// @lc code=end

