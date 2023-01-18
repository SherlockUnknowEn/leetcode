/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map1;
        unordered_map<string, int> map2;
        for (size_t i = 0; i < list1.size(); i++) {
            map1[list1[i]] = i;
        }
        for (size_t i = 0; i < list2.size(); i++) {
            map2[list2[i]] = i;
        }
        vector<string> ans;
        int sum = INT_MAX;
        for (auto& kv : map2) {
            string k = kv.first;
            if (map1.find(k) != map1.end()) {
                if (map1[k] + map2[k] < sum) {
                    ans.clear();
                    ans.push_back(k);
                    sum = map1[k] + map2[k];
                } else if (map1[k] + map2[k] == sum) {
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

