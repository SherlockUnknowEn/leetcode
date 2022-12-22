/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution {
public:
    // TODO: 未完成
    int findUnsortedSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) {
                left = i - 1;
                right = i;
                break;
            }
        }
        if (left == 0 && right == 0)
            return 0;
        cout << left << " " << right << endl;
        for (int i = right; i < nums.size(); i++) {
            cout << " i=" << i << endl;;
            if (nums[i] < nums[i - 1]) {
                // 处理重复
                while (i < nums.size() - 1 && nums[i + 1] == nums[i])
                {
                    i++;
                }
                right = i;
            }
        }
        
        return right - left + 1;
    }
};
// @lc code=end

