/*
 * @lc app=leetcode id=1109 lang=cpp
 *
 * [1109] Corporate Flight Bookings
 */

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> total(n);
        for (int i = 0; i < bookings.size(); i++)
        {
            int first = bookings[i][0];
            int last = bookings[i][1];
            int seats = bookings[i][2];
            total[first - 1] += seats;
            if (last < total.size())
            {
                total[last] -= seats;
            }            
        }
        // 还原total
        for (int i = 1; i < total.size(); i++)
        {
            total[i] = total[i] + total[i-1];
        }
        return total;
    }
};
// @lc code=end

