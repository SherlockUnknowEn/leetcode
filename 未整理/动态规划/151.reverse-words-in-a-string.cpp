/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    // 字符串拼接
    // string reverseWords(string s) {
    //     while (s.length() > 0 && s[0] == ' ')
    //         s = s.substr(1);
    //     if (s == "")
    //         return s;
    //     string res = "";
    //     auto index = s.find(" ");
    //     while (index != string::npos)
    //     {
    //         string a = s.substr(0, index);
    //         res = a + " " + res;
    //         s = s.substr(index+1);
    //         while (s.length() > 0 && s[0] == ' ')
    //             s = s.substr(1);

    //         if (s.length() <= 0)
    //             return res.substr(0, res.length()-1);
    //         index = s.find(" ");
    //     }
    //     if (res.length() > 0)
    //         return s + " " + res.substr(0, res.length() - 1);
    //     else
    //         return s;
    // }

    // 使用栈
    string reverseWords(string s) {
        stack<string> stk;
        string a = "";
        s = s + " "; // 避免最后一个单词被忽略
        for (size_t i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                if (a.length() > 0)
                    stk.push(a);
                a = "";
            }
            else
            {
                a += s[i];
            }
        }
        
        string res = "";
        while (!stk.empty())
        {
            res = res + " " + stk.top();
            stk.pop();
        }
        return res.length() > 0 ? res.substr(1) : res;
    }

};
// @lc code=end

