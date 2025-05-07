/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        // [0, 65535]
        unordered_set<int> set;
        int nums = pow(2, n);
        vector<int> code(nums);
        code[0] = 0;
        set.insert(0);
        for (int i = 1; i < nums; i++) {
            for (int j = 0; j < n; j++) {
                int c = code[i - 1] ^ (1 << j);
                // printf("(1 << j) = %d, c = %d \n", (1 << j), c);
                if (set.find(c) == set.end()) {
                    code[i] = c;
                    set.insert(c);
                    break;
                }
            }
        }
        return code;
    }
};
// @lc code=end

