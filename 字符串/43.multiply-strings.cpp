/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

1 2 3
4 5 6

  1 8

1 5 

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> res(num1.length() + num2.length(), 0);
        vector<int> n1(num1.length());
        vector<int> n2(num2.length());
        for (int i = 0; i < num1.length(); i++) {
            n1[i] = ctoi(num1[num1.length() - 1 - i]);
        }

        for (int i = 0; i < num2.length(); i++) {
            n2[i] = ctoi(num2[num2.length() - 1 - i]);
        }

        for (int i = 0; i < n1.size(); i++) {
            for (int j = 0; j < n2.size(); j++) {
                res[i + j] += (n1[i] * n2[j]);
                if (res[i + j] >= 10)
                {
                    res[i + j + 1] += (res[i + j] / 10);
                    res[i + j] %= 10;
                }
            }
        }
        string s = "";
        int i = res.size() - 1;
        for (; i >= 0; i--)
        {
            if (res[i] != 0)
                break;
        }
        if (i < 0)
        {
            return "0";
        }
        
        for (; i >= 0; i--)
        {
            s += itoc(res[i]);
        }
        return s;
    }

    int ctoi(char s) {
        return s - '0';
    }

    char itoc(int i) {
        return '0' + i;
    }
};
// @lc code=end

