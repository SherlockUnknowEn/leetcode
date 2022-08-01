/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (gas[i] - cost[i]);
        }
        if (sum < 0)
        {
            return -1;
        }
        int start = 0;
        int consume = 0;
        for (int i = 0; i < n; i++)
        {
            consume += (gas[i] - cost[i]);
            if (consume < 0)
            {
                start = i+1;
                consume = 0;
            }
        }
        return start == n ? 0 : start;
    }
};
// @lc code=end

