/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 */

// @lc code=start
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // 1. 对于每个房屋，要么用前面的暖气，要么用后面的，二者取近的，得到距离；
        // 2. 对于所有的房屋，选择最大的上述距离。
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        int cur = 0;
        for (int h : houses) {
            while (cur < heaters.size() - 1 && abs(heaters[cur] - h) >= abs(heaters[cur + 1] - h))
                cur++;
            radius = max(radius, abs(heaters[cur] - h));
        }
        return radius;
    }
};
// @lc code=end

