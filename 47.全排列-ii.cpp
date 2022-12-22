/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp(nums.size());
        vector<int> visited(nums.size(), false);
        traceback(nums, 0, visited, temp);
        return ans;
    }

private:
    void traceback(const vector<int>& nums, int idx, vector<int>& visited, vector<int>& temp)
    {
        if (idx == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i] || i > 0 && nums[i] == nums[i-1] && !visited[i-1])
                continue;
            visited[i] = true;
            temp[idx] = nums[i];
            traceback(nums, idx + 1, visited, temp);
            visited[i] = false;
        }
    }

    vector<vector<int>> ans;
};
// @lc code=end

