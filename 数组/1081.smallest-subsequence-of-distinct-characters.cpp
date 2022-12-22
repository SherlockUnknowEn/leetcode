/*
 * @lc app=leetcode id=1081 lang=cpp
 *
 * [1081] Smallest Subsequence of Distinct Characters
 */

// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> exists(256, false);
        stack<char> stk;
        vector<int> count(256, 0);

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            count[c] += 1;
        }

        // "cbacdcbc"
        
        for (int i = 0; i < s.size(); i++)
        {
            count[s[i]] -= 1;
            
            if (!exists[s[i]])
            {
                while (!stk.empty() && stk.top() > s[i] && count[stk.top()] > 0)
                {
                    exists[stk.top()] = false;
                    stk.pop();
                }
                stk.push(s[i]);
                exists[s[i]] = true;
            }
        }

        string res = "";
        while (!stk.empty())
        {
            res = stk.top() + res;
            stk.pop();
        }
        return res;
    }
};
// @lc code=end

