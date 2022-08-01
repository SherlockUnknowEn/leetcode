/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(256);
        vector<bool> exists(256, false);
        stack<char> stk;

        for (int i = 0; i < s.length(); i++)
        {
            
            count[s[i]] += 1;            
        }
        for (int i = 0; i < s.length(); i++)
        {
            char a = s[i];
            if (!exists[a])
            {
                while (!stk.empty() && stk.top() > a && count[stk.top()] > 0)
                {
                    exists[stk.top()] = false;
                    stk.pop();
                }
                
                stk.push(a);
                exists[a] = true;
            }
            count[a]--;
        }
        string res = "";
        while (!stk.empty())
        {
            char a = stk.top();
            res = string(1, a) + res;
            stk.pop();
        }
        
        return res;
    }
};
// @lc code=end

