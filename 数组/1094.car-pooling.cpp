/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        const int MaxLen = 1001;
        vector<int> diff(MaxLen);
        for (int i = 0; i < trips.size(); i++)
        {
            int numsPass = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];
            if (numsPass > capacity)
            {
                return false; // base case  0站上车人数已经大于capcity
            }
            
            diff[from] += numsPass;
            if (to < MaxLen - 1) //  to 站已经下车  应该在此站减去 而不是 to+1 站减去
            {
                diff[to] -= numsPass;
            }
        }

        for (int i = 1; i < MaxLen; i++)
        {
            diff[i] = diff[i] + diff[i-1];
            if (diff[i] > capacity)
            {
                return false;
            }
            
        }
        return true;
    }
};
// @lc code=end

