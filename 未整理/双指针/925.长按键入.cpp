/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (name[0] != typed[0]) return false;
        char pre = name[0];
        int j = 1;
        for (int i = 1; i < name.size(); i++) {
            if (typed[j] == name[i]) {
                j++;
            } else {
                while (typed[j] == pre) 
                    j++;
                if (typed[j] != name[i]) {
                    return false;
                } else {
                    j++;
                }
            }
            pre = name[i];
        }
        for (; j < typed.size(); j++) {
            if (typed[j] != pre)
                return false;
        }
        return true;
    }
};
// @lc code=end

