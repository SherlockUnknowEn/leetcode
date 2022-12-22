/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stk.push(s[i]);
            }
            else
            {
                if (stk.empty())
                {
                    return false;
                }
                
                if (s[i] == ')' && stk.top() != '(' 
                    || s[i] == ']' && stk.top() != '[' 
                    || s[i] == '}' && stk.top() != '{')
                {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};
// @lc code=end

