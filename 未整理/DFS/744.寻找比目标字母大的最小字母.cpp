/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // if (target > letters[letters.size() - 1])
        //     return letters[0];
        // for (char c : letters) {
        //     if (c > target)
        //         return c;
        // }
        // return letters[0];
        vector<char>::iterator c = upper_bound(letters.begin(), letters.end(), target);
        if (c == letters.end())
            return letters[0];
        return *c;
    }
};
// @lc code=end

