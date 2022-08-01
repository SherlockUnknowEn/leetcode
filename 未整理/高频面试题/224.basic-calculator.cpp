/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return helper(s, i);
    }

    int helper(const string& s, int& i)
    {
        stack<int> nums;
        char sign = '+';
        int n = 0;
        while (i < s.length())
        {
            if (isdigit(s[i]))
            {
                n = n * 10 + (s[i] - '0');
            }
            if (s[i] == '(')
            {
                n = helper(s, ++i);
            }
            if (!isdigit(s[i]) && (s[i] != ' ') || i == s.length() - 1)
            {
                if (sign == '+')
                {
                    nums.push(n);
                } 
                else if (sign == '-')
                {
                    nums.push(0-n);
                }
                sign = (s[i] == '-') ? '-' : '+';
                n = 0;
            }
            if (s[i] == ')')
            {
                i++;
                break;
            }
            i++;
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

