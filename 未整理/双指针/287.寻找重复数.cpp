/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 本题为求环形链表的入口 数组形式题
        // 快慢指针
        int slow = 0;
        int fast = 0;
        while (slow != fast || slow == 0)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;

    }
};
// @lc code=end

