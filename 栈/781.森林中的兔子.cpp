/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */

// @lc code=start
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> mp(1001);
        int result = 0;
        for (int a : answers) {
            if (mp[a] > 0) {
                mp[a]--;
            } else {
                mp[a] = a;
                result += (a + 1);
            }
        }
        return result;
    }
};
// @lc code=end

