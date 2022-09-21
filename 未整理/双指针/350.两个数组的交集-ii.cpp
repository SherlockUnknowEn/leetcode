/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;
        for (auto c: nums1)
            map1[c]++;
        for (auto c: nums2)
            map2[c]++;
        vector<int> ans;
        for (auto iter = map1.begin(); iter != map1.end(); ++iter)
        {
            int key = iter->first;
            if (map2[key] > 0) {
                int n = min(map1[key], map2[key]);
                for (int j = 0; j < n; j++)
                    ans.push_back(key);
            }
        }
        return ans;
    }
};
// @lc code=end

