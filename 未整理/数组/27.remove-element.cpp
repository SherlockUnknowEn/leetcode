/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cur = 0;
        int i = 0;
        int length = 0;
        while (i < nums.size())
        {
            if (nums[i] != val)
            {
                nums[cur] = nums[i];
                i++;
                cur++;
                length++;
            } 
            else 
            {
                i++;
            }
        }
        return length;
    }
};
// @lc code=end

