/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0;
        int j = 1;
        for (int n : nums) {
            int o = n & 0xFFFF;
            // cout << n << " " << o << " " << i << " " << j << " ";
            if (o % 2 == 0) {
                o = o << 16;
                // cout << o << endl;
                nums[i] = nums[i] | o;
                i += 2;
            } else {
                o = o << 16;
                // cout << o << endl;
                nums[j] = nums[j] | o;
                j += 2;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            // cout << i << "." << nums[i] << " " << (nums[i] >> 16) << endl;
            nums[i] = nums[i] >> 16;
        }
        return nums;
    }
};
// @lc code=end

