/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m;
        for (int a : nums1)
        {
            for (int b : nums2)
            {
                m[a + b]++;
            }
        }
        int res = 0;

        for (int c : nums3)
        {
            for (int d : nums4)
            {
                res += m[0 - (c + d)];  
            }
        }
        return res;
    }
};
// @lc code=end

