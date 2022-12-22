/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */

// @lc code=start
class Solution {
public:
    // void duplicateZeros(vector<int>& arr) {
    //     vector<int> a(arr);
    //     int idx = 0;
    //     for (int i = 0; i < a.size() - 1; i++) {
    //         if (idx >= arr.size()) break;
    //         if (a[i] == 0) {
    //             arr[idx++] = 0;
    //             if (idx >= arr.size()) break;
    //         } 
    //         arr[idx++] = a[i];
    //     }
    // }

    void duplicateZeros(vector<int>& arr) {
        int j = 0;
        for (int i = 0; j < arr.size(); i++) {
            if ((arr[i] & 0x0f) == 0) {
                j += 2; // 0 - 9 高4位为0  不用操作
            } else {
                arr[j++] |= ((arr[i] & 0x0f) << 4); // 低四位为arr[i]原来的值
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = (arr[i] >> 4);
        }
    }
};
// @lc code=end

