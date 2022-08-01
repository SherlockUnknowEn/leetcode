/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        int n = 0;
        char sign = '+';
        int index = 0;
        while (index <= s.length())
        {
            int c = s[index];
            if (isdigit(c))
            {
                n = n * 10 + (c - '0'); 
            }
            if ((!isdigit(c) && c !=' ') || index == s.length())
            {
                if (sign == '+')
                {
                    nums.push(n);
                    n = 0;
                }
                if (sign == '-')
                {
                    nums.push(-n);
                    n = 0;
                }
                if (sign == '*')
                {
                    int a = nums.top();
                    nums.pop();
                    nums.push(a * n);
                    n = 0;
                }
                if (sign == '/')
                {
                    int a = nums.top();
                    nums.pop();
                    nums.push(a / n);
                    n = 0;
                }
                if (c == '+' || c == '-' || c == '*' || c == '/')
                {
                    sign = c;
                }
            }
            index++;
        }
        int sum = 0;
        while (!nums.empty())
        {
            sum += nums.top();
            nums.pop();
        }
        return sum;
    }

};
// @lc code=end

