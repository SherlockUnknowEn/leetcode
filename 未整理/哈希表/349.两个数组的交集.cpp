/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int MAX_ITEM = 1000;
        unordered_set<int> result_set;
        vector<bool> table(MAX_ITEM + 1, false);
        for (size_t i = 0; i < nums1.size(); i++)
        {
            table[nums1[i]] = true;
        }
        for (size_t i = 0; i < nums2.size(); i++)
        {
            if (table[nums2[i]])
            {
                result_set.insert(nums2[i]);
            }
            
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};
// @lc code=end

