/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        for (string& s : operations) {
            if (s == "+") {
                int sz = scores.size();
                scores.push_back(scores[sz - 1] + scores[sz - 2]);
            } else if (s == "D") {
                scores.push_back(scores[scores.size() - 1] * 2);
            } else if (s == "C") {
                scores.pop_back();
            } else {
                scores.push_back(stoi(s));
            }
        }
        int sum = 0;
        for (int c : scores) {
            sum += c;
        }
        return sum;
    }
};
// @lc code=end

