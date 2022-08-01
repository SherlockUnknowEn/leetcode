/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start

#include <stdio.h>
#include <string>
#include <vector>

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.push_back(vector<int>());
        int count = 0;
        int pre = nums[0];
        for (int i = 0; i < nums.size(); )
        {
            while (i < nums.size() && nums[i] == pre)
            {
                count++;
                i++;
            }
            int tmp = res.size();
            for (int j = 0; j < tmp; j++)
            {
                for (int k = 1; k < count + 1; k++) {
                    vector<int> a(k, pre);
                    vector<int> n = res[j];
                    n.insert(n.end(), a.begin(), a.end());
                    res.push_back(n);
                }
            }
            pre = i < nums.size() ? nums[i] : pre;
            count = 0;
        }
        return res;
    }
};
// @lc code=end
