/*
 * @lc app=leetcode id=1541 lang=cpp
 *
 * [1541] Minimum Insertions to Balance a Parentheses String
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
        int count = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(') 
            {
                if (right % 2 != 0) // 奇数  不配对
                {
                    right -= 1;
                    count++; // 有插入操作
                }
                
                right += 2;
            }
            if (s[i] == ')')
            {
                right -= 1;
                if (right == -1) // 右括号太多   这里不能为 -2 因为 ')(' 这种情况会在 -1 时 right + 2 导致忽略 ')'
                {
                    count += 1; // 有插入操作
                    right = 1;
                }
                
            }
        }
        return count + right;
    }
};
// @lc code=end

