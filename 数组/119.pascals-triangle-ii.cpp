/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
        {
            return { 1 };
        }
        vector<int> cur = {1, 1};
        for (int i = 1; i < rowIndex; i++)
        {
            vector<int> next;
            next.push_back(1);
            for (int j = 0; j < cur.size() - 1; j++)
            {
                next.push_back(cur[j] + cur[j+1]);
            }
            next.push_back(1);
            cur = next;
        }
        
        return cur;
    }
};
// @lc code=end

