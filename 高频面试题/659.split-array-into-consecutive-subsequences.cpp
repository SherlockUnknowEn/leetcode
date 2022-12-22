/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 */

// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // 122334
        unordered_map<int, int> pool;
        unordered_map<int, int> end;
        for (int i = 0; i < nums.size(); i++)
        {
            pool[nums[i]]++;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int val = nums[i];
            if (pool[val] <= 0) continue;
            pool[val]--;
            if (end[val] > 0) // 放入某个子序列末尾
            {
                end[val]--;
                end[val+1]++;
            }
            else if (pool[val + 1] > 0 && pool[val + 2] > 0) // 有连续3张则能组成新子序列
            {
                pool[val + 1]--;
                pool[val + 2]--;
                end[val + 3]++;
            }
            else
                return false;
        }
        return true;
    }

};
// @lc code=end

