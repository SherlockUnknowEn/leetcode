/*
 * @lc app=leetcode.cn id=825 lang=cpp
 *
 * [825] 适龄的朋友
 */

// @lc code=start
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        int ans = 0;
        int AM = 121;
        vector<int> cnt(AM);
        for (int age : ages) {
            cnt[age]++;
        }
        vector<int> pre(AM);
        pre[0] = cnt[0];
        for (int i = 1; i < AM; i++) {
            pre[i] = pre[i-1] + cnt[i];
        }
        for (int i = 15; i < AM; i++) {
            if (cnt[i] > 0) {
                int y = i * 0.5 + 7;
                ans = ans + cnt[i] * (pre[i] - pre[y] - 1);
            }
        }
        return ans;
        
    }
};
// @lc code=end

