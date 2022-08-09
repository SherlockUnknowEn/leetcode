/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        vector<int> table = { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
        int num = 0;
        s.insert(n);
        while (1)
        {
            while (n)
            {
                num += table[n % 10];
                n = n / 10;
            }

            if (num == 1)
                return true;
            if (s.find(num) != s.end())
                return false;
            n = num;        
            num = 0;            
            s.insert(n);
        }
    }
};
// @lc code=end

