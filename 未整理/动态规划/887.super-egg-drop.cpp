/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 */

// @lc code=start
class Solution {
public:
    int superEggDrop(int k, int n) {
        return dp(k, 1, n);
    }


    int dp(int k, int low, int hight) {
        if (k == 1) // 没有鸡蛋了
            return hight - low + 1;
        if (hight <= low) // 最后一层楼
            return 1;
        string key = to_string(k) + "," + to_string(hight - low + 1);
        if (memo.find(key) != memo.end())
        {
            return memo[key];
        }
        
        int res = INT_MAX;
        for (int i = low; i < hight + 1; i++)
        {
            int a = max(dp(k, i+1, hight), dp(k-1, low, i-1)) + 1;
            res = min(res, a);
        }
        memo[key] = res;
        return res;
    }

private:
    unordered_map<string, int> memo;
};
// @lc code=end

