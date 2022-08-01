/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sub;
        backtrack(candidates, target, sub, 0, 0);
        return res;
    }

    void backtrack(const vector<int>& candidates, int target, vector<int>& sub, int left, int sum)
    {
        if (sum == target)
        {
            res.push_back(sub);
            return;
        }
        for (int i = left; i < candidates.size(); i++)
        {
            int val = candidates[i];
            if (sum + val > target)
            {
                continue;
            }
            sum += val;
            sub.push_back(val);
            backtrack(candidates, target, sub, i, sum);
            sub.pop_back();
            sum -= val;
        }
        
    }

private:
    vector<vector<int>> res;
};
// @lc code=end

