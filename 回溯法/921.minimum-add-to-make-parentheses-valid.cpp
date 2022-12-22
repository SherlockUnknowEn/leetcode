/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        int right = 0;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                right += 1; // 右括号需要一个
            }
            else
            {
                right -= 1;
                if (right == -1)
                {
                    count++; // 需要插入左括号
                    right = 0;
                }
            }
        }
        return count + right;
    }
};
// @lc code=end

