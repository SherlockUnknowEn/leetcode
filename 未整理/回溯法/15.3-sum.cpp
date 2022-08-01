/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();)
        {
            int a = nums[i];
            vector<vector<int>> t = twoSum(nums, 0 - a, i + 1, nums.size() - 1);
            for (auto item : t)
            {
                res.push_back({a, item[0], item[1]});
            }
            
            while (i < nums.size() && nums[i] == a) i++;
        }
        
        return res;
    }

    vector<vector<int>> twoSum(const vector<int>& nums, int target, int i, int j)
    {
        vector<vector<int>> t;
        while (i < j)
        {
            int a = nums[i];
            int b = nums[j];
            if (a + b == target)
            {
                t.push_back({ a, b });
                while (i < j && nums[i] == a) i++;
                while (i < j && nums[j] == b) j--;
            }
            if (a + b > target)
            {
                j--;
            }
            if (a + b < target)
            {
                i++;
            }
        }
        
        return t;
    }

private:
    vector<vector<int>> res;
};
// @lc code=end

