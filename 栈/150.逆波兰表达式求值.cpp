/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (auto& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                if (t == "+") {
                    nums.push(b + a);
                }
                if (t == "-") {
                    nums.push(b - a);
                }
                if (t == "*") {
                    nums.push(b * a);
                }
                if (t == "/") {
                    nums.push(b / a);
                }
            } else {
                nums.push(stoi(t));
            }
        }
        // printf("nums.size() = %d\n", nums.size());
        return nums.top();
    }
};
// @lc code=end

