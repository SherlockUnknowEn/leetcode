/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0;
        int right = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            left = max(nums[i], left);
            right = right + nums[i];
        }
        while (left <= right)
        {
            int sum = left + (right - left) / 2;
            if (f(nums, sum) == m)
            {
                right = sum - 1;
            }
            else if (f(nums, sum) < m)
            {
                right = sum - 1;
            }
            else if (f(nums, sum) > m)
            {
                left = sum + 1;
            }
        }
        return left;
    }

    int f(const vector<int>& nums, int sum)
    {
        int m = 1;
        int a = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            
            if (a + nums[i] > sum)
            {
                a = 0;
                m++;
            }
            a += nums[i];
        }
        return m;
    }
};
// @lc code=end



