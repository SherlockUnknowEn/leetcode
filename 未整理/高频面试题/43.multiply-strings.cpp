/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length();
        int n2 = num2.length();
        vector<int> nums(n1 + n2);
        for (int i = num2.length()-1; i >= 0; i--)
        {
            for (int j = num1.length()-1; j >= 0; j--) 
            {
                int a = num1[j] - '0';
                int b = num2[i] - '0';
                int r = a * b;
                r = nums[i + j + 1] + r;
                nums[i + j + 1] = r % 10;
                nums[i + j] = nums[i + j] + r / 10;
            }
        }
        int i = 0;
        while (i < nums.size() && nums[i] == 0)
        {
            i++;
        }
        string result = "";
        while (i < nums.size() )
        {
            result += (nums[i] + '0');
            i++;
        }
        return result.size() == 0 ? "0" : result;
    }

};
// @lc code=end

