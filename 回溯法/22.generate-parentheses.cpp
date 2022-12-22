/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
int ni = 0;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        backtrack(0, 0, n, s);
        return res;
    }

    void backtrack(int left, int right, int n, string& s) // 选择路径为 放一个 左括号 / 右括号, left right 记录已经放了多少个左括号和右括号
    {
        if (left < right)
        {
            return;
        }
        if (left > n || right > n)
        {
            return;
        }
        if (left == n && right == n)
        {
            res.push_back(s);
            return;
        }
        
        
        s.push_back('(');
        backtrack(left+1, right, n, s);
        s.pop_back(); // 撤销

        s.push_back(')');
        backtrack(left, right+1, n, s);
        s.pop_back(); // 撤销
        
    }

    void printIndex(int n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("  ");
        }        
    }
private:
    vector<string> res;
};
// @lc code=end

