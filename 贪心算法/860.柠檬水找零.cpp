/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0;
        int ten = 0;
        for (size_t i = 0; i < n; i++)
        {
            int b = bills[i];
            if (b == 5)
                five++;
            if (b == 10)
            {
                if (five <= 0)
                    return false;
                ten++;
                five--;
            }
            if (b == 20)
            {
                if (ten > 0 && five > 0)
                {
                    five--;
                    ten--;
                }
                else if (five >= 3)
                    five -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

