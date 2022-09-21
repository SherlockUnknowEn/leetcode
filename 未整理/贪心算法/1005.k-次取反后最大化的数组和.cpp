/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
public:
    static bool cmp(int a, int b)
    {
        return abs(a) > abs(b);
    } 

    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), Solution::cmp);
        for (size_t i = 0; i < n; i++)
        {
            if (k <= 0)
                break;
            
            if (nums[i] < 0)
            {
                nums[i] = -nums[i];
                k--;
            }
        }
        nums[n - 1] = (k % 2 == 0) ? nums[n - 1] : -nums[n - 1];
        int sum = 0;
        for (int a : nums)
        {
            sum += a;
        }
        return sum;
    }
};
// @lc code=end

