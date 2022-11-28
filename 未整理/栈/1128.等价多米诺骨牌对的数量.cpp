/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

// @lc code=start
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int sz = dominoes.size();
        vector<int> memo(100);
        int cnt = 0;
        for (int i = 0; i < sz; i++) {
            // vector<int>& t = dominoes[i];
            int a = max(dominoes[i][0], dominoes[i][1]);
            int b = min(dominoes[i][0], dominoes[i][1]);
            int c = a * 10 + b;
            cnt += memo[c];
            memo[c]++;
        }
        return cnt;
    }
};
// @lc code=end

