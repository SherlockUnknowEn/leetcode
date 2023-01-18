/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int, int> memo;
        for (int c : candyType) {
            memo[c]++;
        }
        return min(candyType.size() / 2, memo.size());
    }
};
// @lc code=end

