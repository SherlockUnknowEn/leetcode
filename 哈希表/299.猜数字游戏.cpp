/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        // 数字对了 - 数字和位置全对了
        // 1. 数字 位置全对了
        int count1 = 0;
        // 2. 数字对了，不论顺序
        int count2 = 0;
        vector<int> m1(10);
        vector<int> m2(10);
        int n = secret.size();
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i])
            {
                count1++;
            }
            m1[secret[i] - '0']++;
            m2[guess[i] - '0']++;
        }
        for (size_t i = 0; i < 10; i++)
        {
            count2 += min(m1[i], m2[i]);
        }
        stringstream oss;
        oss << count1 << "A" << count2 - count1 << "B";
        return oss.str();
    }
};
// @lc code=end

